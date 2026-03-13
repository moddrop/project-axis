#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <HTTPClient.h>
#include "ESP_I2S.h"
#include "esp_camera.h"
#include "base64.h"
#include <ArduinoJson.h>
#include "Audio.h"
/* ===================== CONFIG ===================== */
const char* WIFI_SSID = "SmartGlass";
const char* WIFI_PASS = "Caleb180113";
const char* OPENAI_API_KEY = "";

/* ===================== GLOBALS ===================== */
WiFiClientSecure tls;
I2SClass i2s;
bool cameraOK = false;
#define I2S_DOUT            D2
#define I2S_BCLK            D1
#define I2S_LRC             D0
Audio audio;
/* ===================== CAMERA CONFIG ===================== */
camera_config_t cam = {
  .pin_pwdn  = -1,
  .pin_reset = -1,
  .pin_xclk = 10,
  .pin_sccb_sda = 40,
  .pin_sccb_scl = 39,

  .pin_d7 = 48, .pin_d6 = 11, .pin_d5 = 12, .pin_d4 = 14,
  .pin_d3 = 16, .pin_d2 = 18, .pin_d1 = 17, .pin_d0 = 15,

  .pin_vsync = 38,
  .pin_href  = 47,
  .pin_pclk  = 13,

  .xclk_freq_hz = 20000000,
  .ledc_timer   = LEDC_TIMER_0,
  .ledc_channel = LEDC_CHANNEL_0,

  .pixel_format = PIXFORMAT_JPEG,
  .frame_size   = FRAMESIZE_VGA,
  .jpeg_quality = 20,
  .fb_count     = 1,

  .fb_location = CAMERA_FB_IN_PSRAM,
  .grab_mode   = CAMERA_GRAB_WHEN_EMPTY
};

/* ===================== HELPERS ===================== */

String parseTranscription(const String& body) {
  DynamicJsonDocument doc(1024);
  if (deserializeJson(doc, body)) return "";
  return doc["text"] | "";
}

String parseVision(const String& body) {
  DynamicJsonDocument doc(2048);
  if (deserializeJson(doc, body)) return "";
  return doc["output"][0]["content"][0]["text"] | "";
}

String ChatGPT(String response) {
    int start = response.indexOf("\"content\": \"");
  if (start < 0) return "";
  start += 12;   // length of "content": "
  int end = response.indexOf("\",", start);
  if (end < 0) return "";
  return response.substring(start, end);
}
/* ===================== AUDIO ===================== */
String sendToChatGPT(const String& prompt) {
  const char* host = "api.openai.com";
  const int httpsPort = 443;

  WiFiClientSecure client;
  client.setInsecure();

  if (!client.connect(host, httpsPort)) {
    Serial.println("HTTPS connection failed.");
  }

  String safePrompt = prompt;
  safePrompt.replace("\"", "'");

  String body =
    "{"
      "\"model\":\"gpt-4.1-mini\","
      "\"messages\":["
        "{\"role\":\"user\",\"content\":\"" + safePrompt + "\"}"
      "]"
    "}";

  String request =
    String("POST /v1/chat/completions HTTP/1.1\r\n") +
    "Host: " + host + "\r\n" +
    "Authorization: Bearer " + OPENAI_API_KEY + "\r\n" +
    "Content-Type: application/json\r\n" +
    "Content-Length: " + String(body.length()) + "\r\n" +
    "Connection: close\r\n\r\n" +
    body;

  client.print(request);
  Serial.println("🤖 Sent transcription to ChatGPT...");

  unsigned long timeout = millis() + 20000;
  String response = "";

  while (client.connected() && millis() < timeout) {
    while (client.available()) {
      response += (char)client.read();
    }
  }
  String me=ChatGPT(response);
  return me;
}

String runAudio() {
  i2s.begin(I2S_MODE_PDM_RX, 18000, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_MONO);

  size_t wavSize = 0;
  uint8_t* wav = i2s.recordWAV(5, &wavSize);
  if (!wav) {
    i2s.end();
    return "Mic failed";
  }
  Serial.println("recording done");
  tls.stop();
  if (!tls.connect("api.openai.com", 443)) {
    free(wav);
    i2s.end();
    return "TLS failed";
  }

  String boundary = "----ESP32Audio";
  String head =
    "--" + boundary + "\r\n"
    "Content-Disposition: form-data; name=\"model\"\r\n\r\n"
    "gpt-4o-mini-transcribe\r\n"
    "--" + boundary + "\r\n"
    "Content-Disposition: form-data; name=\"file\"; filename=\"audio.wav\"\r\n"
    "Content-Type: audio/wav\r\n\r\n";

  String tail = "\r\n--" + boundary + "--\r\n";
  size_t len = head.length() + wavSize + tail.length();

  tls.printf(
    "POST /v1/audio/transcriptions HTTP/1.1\r\n"
    "Host: api.openai.com\r\n"
    "Authorization: Bearer %s\r\n"
    "Content-Type: multipart/form-data; boundary=%s\r\n"
    "Content-Length: %u\r\n"
    "Connection: close\r\n\r\n",
    OPENAI_API_KEY, boundary.c_str(), (unsigned)len
  );

  tls.print(head);
  tls.write(wav, wavSize);
  tls.print(tail);
  free(wav);

  String resp;
  unsigned long t = millis();
  bool bodyStarted = false;

  while (tls.connected() && millis() - t < 5000) {
    while (tls.available()) {
      char c = tls.read();
      if (!bodyStarted) {
        resp += c;
        if (resp.endsWith("\r\n\r\n")) {
          resp = "";
          bodyStarted = true;
        }
      } else {
        resp += c;
        if (resp.endsWith("}")) break;
      }
    }
  }

  tls.stop();
  i2s.end();
  String hi=parseTranscription(resp);
  return sendToChatGPT(hi);
}

/* ===================== VISION ===================== */
String runVision() {
  if (!cameraOK) return "Camera unavailable";

  camera_fb_t* fb = esp_camera_fb_get();
  if (!fb) return "Capture failed";

  if (fb->len > 180000) {
    esp_camera_fb_return(fb);
    return "Image too large";
  }

  String img = base64::encode(fb->buf, fb->len);
  esp_camera_fb_return(fb);

  String payload =
    "{"
    "\"model\":\"gpt-4.1-mini\","
    "\"input\":[{"
      "\"role\":\"user\","
      "\"content\":["
        "{\"type\":\"input_text\",\"text\":\"Describe the image.\"},"
        "{\"type\":\"input_image\",\"image_url\":\"data:image/jpeg;base64," + img + "\"}"
      "]"
    "}]"
    "}";

  HTTPClient http;
  http.begin(tls, "https://api.openai.com/v1/responses");
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", String("Bearer ") + OPENAI_API_KEY);
  http.addHeader("Connection", "close");

  http.POST(payload);
  String body = http.getString();
  http.end();

  img = "";
  payload = "";

  return parseVision(body);
}

/* ===================== SETUP ===================== */
void setup() {
  Serial.begin(115200);

  if (!psramFound()) {
    Serial.println("PSRAM REQUIRED");
    while (1);
  }

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) delay(200);

  tls.setInsecure();
  i2s.setPinsPdmRx(42, 41);

  cameraOK = (esp_camera_init(&cam) == ESP_OK);
  Serial.println(cameraOK ? "Camera OK" : "Camera FAILED");

  Serial.println("System ready");
  pinMode(D3,OUTPUT);
  digitalWrite(D3,HIGH);
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(20);
  audio.openai_speech(OPENAI_API_KEY, "tts-1", "System ready.", "", "shimmer", "mp3", "1");
    while (audio.isRunning()) {
    audio.loop();
    delay(1);
  }
}

/* ===================== LOOP ===================== */
void loop() {
  Serial.println("Audio:");
  String aud=runAudio();
  audio.openai_speech(OPENAI_API_KEY, "tts-1", aud, "", "shimmer", "mp3", "1");
  while (audio.isRunning()) {
    audio.loop();
    delay(1);
  }
  Serial.println(aud);

  delay(3000);
}


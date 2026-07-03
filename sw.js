self.addEventListener("install", () => self.skipWaiting());
self.addEventListener("activate", e => e.waitUntil(clients.claim()));

self.addEventListener("push", event => {
  let data = {};
  try { data = event.data?.json() || {}; } catch {}
  event.waitUntil(
    clients.matchAll({ type: "window", includeUncontrolled: true }).then(list => {
      if (list.some(c => c.visibilityState === "visible")) return;
      return self.registration.showNotification(data.title || "Project Axis", {
        body:      data.body || "New message",
        icon:      "/logo.png",
        badge:     "/logo.png",
        tag:       data.tag  || "pa",
        renotify:  true,
        data:      { url: data.url || "/dashboard.html" },
      });
    })
  );
});

self.addEventListener("notificationclick", event => {
  event.notification.close();
  const url = event.notification.data?.url || "/dashboard.html";
  event.waitUntil(
    clients.matchAll({ type: "window", includeUncontrolled: true }).then(list => {
      for (const c of list) {
        if ("focus" in c) return c.focus();
      }
      return clients.openWindow(url);
    })
  );
});

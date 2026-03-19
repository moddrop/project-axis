console.log ("For translation, when you want to enter English, please click on the 'x' on the Google Translate bar on top of the navbar. Also if you are having trouble with setting your system language to English on your device please search your device model and try to fix the system settings.");

var acc = document.getElementsByClassName("accordion");
var i;

for (i = 0; i < acc.length; i++) {
    acc[i].addEventListener("click", function () {
        this.classList.toggle("active");
        var panel = this.nextElementSibling;
        if (panel.style.display === "block") {
            panel.style.display = "none";
        } else {
            panel.style.display = "block";
        }
    });
}

// error
function submit() {
    let password = document.getElementById("portal").value;
    let caleb = "caleb";

    if (password === caleb) {
        document.body.style.backgroundColor="red";
    } else {
        alert("Incorrect Password")
    }
}

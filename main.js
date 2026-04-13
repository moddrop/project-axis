const caroselleftbtnEl = document.getElementById('caroselleftbtn');
const caroselrightbtnEl = document.getElementById('caroselrightbtn');
const caroselitemEl = document.querySelectorAll('.carosel-item');
const hamburgerBtn = document.getElementById('hamburgerBtn');
const mobileMenu = document.getElementById('mobileMenu');
const numimages = 3;

const end = (100 * (numimages - 1));
let start = 0;

caroselleftbtnEl.addEventListener("click", () => {
    if (start < 0) {
        start = start + 100;
    }
    caroselitemEl.forEach(element => {
        element.style.transform = `translateX(${start}%)`;
    })
})

caroselrightbtnEl.addEventListener("click", () => {
    if (start > -end) {
        start = start - 100;
    }
    caroselitemEl.forEach(element => {
        element.style.transform = `translateX(${start}%)`;
    })
})

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



console.log("For translation, when you want to enter English, please click on the 'x' on the Google Translate bar on top of the navbar. Also if you are having trouble with setting your system language to English on your device please search your device model and try to fix the system settings.");
//Claude

hamburgerBtn.addEventListener('click', () => {
    hamburgerBtn.classList.toggle('open');
    mobileMenu.classList.toggle('open');
});

// Close menu when a link is tapped
mobileMenu.querySelectorAll('a').forEach(link => {
    link.addEventListener('click', () => {
        hamburgerBtn.classList.remove('open');
        mobileMenu.classList.remove('open');
    });
});

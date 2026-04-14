const carouselLeftBtn = document.getElementById('caroselleftbtn');
const carouselRightBtn = document.getElementById('caroselrightbtn');
const carouselItems = document.querySelectorAll('.carosel-item');
const hamburgerBtn = document.getElementById('hamburgerBtn');
const mobileMenu = document.getElementById('mobileMenu');
const acc = document.getElementsByClassName("accordion");

let start = 0;
const numImages = carouselItems.length;
const end = 100 * (numImages - 1);

function updateCarousel() {
    carouselItems.forEach(el => {
        el.style.transform = `translateX(${start}%)`;
    });
}

if (carouselLeftBtn && carouselRightBtn && carouselItems.length > 0) {

    carouselLeftBtn.addEventListener("click", () => {
        if (start < 0) start += 100;
        updateCarousel();
    });

    carouselRightBtn.addEventListener("click", () => {
        if (start > -end) start -= 100;
        updateCarousel();
    });
}

if (acc.length > 0) {
    for (let i = 0; i < acc.length; i++) {
        acc[i].addEventListener("click", function () {

            const panel = this.nextElementSibling;
            const isOpen = panel.style.maxHeight;

            for (let j = 0; j < acc.length; j++) {
                acc[j].classList.remove("active");
                acc[j].nextElementSibling.style.maxHeight = null;
            }

            if (!isOpen) {
                this.classList.add("active");
                panel.style.maxHeight = panel.scrollHeight + "px";
            }
        });
    }
}

if (hamburgerBtn && mobileMenu) {

    hamburgerBtn.addEventListener('click', () => {
        hamburgerBtn.classList.toggle('open');
        mobileMenu.classList.toggle('open');
    });

    mobileMenu.querySelectorAll('a').forEach(link => {
        link.addEventListener('click', () => {
            hamburgerBtn.classList.remove('open');
            mobileMenu.classList.remove('open');
        });
    });
}
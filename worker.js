async function loadCountdown() {
    try {
        const res = await fetch("https://countdown-api.calebethan485.workers.dev/countdown");
        const target = await res.json();
        startTimer(Number(target));
    } catch (e) {
        startTimer(1814572800000);
    }
}

function startTimer(target) {
    const el = document.getElementById("timer");
    if (!el) return;

    function tick() {
        const diff = target - Date.now();

        if (diff <= 0) {
            el.textContent = "LAUNCHED";
            return;
        }

        const d = Math.floor(diff / 86400000);
        const h = Math.floor(diff % 86400000 / 3600000);
        const m = Math.floor(diff % 3600000 / 60000);
        const s = Math.floor(diff % 60000 / 1000);

        el.textContent = `Project Coming Soon: ${d}d ${h}h ${m}m ${s}s`;
        setTimeout(tick, 1000);
    }

    tick();
}

window.addEventListener("load", loadCountdown);

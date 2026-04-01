
async function loadCountdown() {

    const target = 1778976000000;

    startTimer(target);
}

function startTimer(target) {

    setInterval(() => {

        const diff = target - Date.now();

        if (diff <= 0) {
            document.getElementById("timer").textContent = "LAUNCHED";
            return;
        }

        const d = Math.floor(diff / 86400000);
        const h = Math.floor(diff % 86400000 / 3600000);
        const m = Math.floor(diff % 3600000 / 60000);
        const s = Math.floor(diff % 60000 / 1000);

        document.getElementById("timer").textContent = "Project Coming Soon: "+
            `${d}d ${h}h ${m}m ${s}s`;

    }, 1000);
}
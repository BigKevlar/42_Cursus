const { parentPort } = require("worker_threads");
const { performance } = require("perf_hooks");


function calculateAcceleration(elapsedTime, currentSpeed, maxSpeed) {
    const minTime = 7.5;   // milisegundos, lo más rápido que alguien puede pulsar
    const maxTime = 100; // más lento que esto es como no correr
    const maxAcc = 8;    // aceleración máxima
    const minAcc = -5;   // desaceleración si pulsas mal o muy lento

    // Clamp the value entre minTime y maxTime
    const clampedTime = Math.min(Math.max(elapsedTime, minTime), maxTime);

    // Cuanto más cerca de minTime, más aceleración. Hacemos una función inversa:
    const norm = 1 - (clampedTime - minTime) / (maxTime - minTime);

    // Penalización basada en la velocidad actual
    const speedPenalty = 1 - (currentSpeed / maxSpeed); // Cuanto más cerca del maxSpeed, menor será este valor

    // La aceleración final se reduce por el factor de penalización
    return (norm * maxAcc + (1 - norm) * minAcc) * speedPenalty;
}

function HandleSteps(last_foots, direction) {
    if (last_foots.foot1 === null) {
        last_foots.foot1 = direction;
        last_foots.time = performance.now();
    }
    else
    {
        last_foots.foot1 = last_foots.foot2;
        last_foots.foot2 = direction;
        last_foots.time -= performance.now();
        if (last_foots.time <= 0)
            last_foots.time = performance.now();
    }
}

function SologameLogic(state) {
    const maxSpeed = 15; // m/s
    const minSpeed = 3; // m/s
    const maxAcceleration = 10; // m/s^2
    let last_footsp1 = {time: performance.now(), foot1: null, foot2: null};
    let last_footsp2 = {time: performance.now(), foot1: null, foot2: null};
    parentPort.on("message", (message) => {
        if (message.type === "p1-left")
            HandleSteps(last_footsp1, 'left');
        else if (message.type === "p1-right")
            HandleSteps(last_footsp1, 'right');
        else if (message.type === "p2-left")
            HandleSteps(last_footsp2, 'left');
        else if (message.type === "p2-right")
            HandleSteps(last_footsp2, 'right');
    });
    
    let interval1 = setInterval(() => {
        //actualizar el estado del jugador 1
        if (!state.player1.isfallen)
        {
            state.player1.speed += state.player1.acceleration / 60;
            if (state.player1.speed > maxSpeed) 
                state.player1.speed = maxSpeed;
            else if (state.player1.speed < minSpeed)
                state.player1.speed = minSpeed;
            state.player1.distance += state.player1.speed / 60;
        }
        state.player1.time += 0.0166666666667;
        if (state.player1.distance >= 100)
        {
            if (state.winner === null) 
                state.winner = "player1";
            else
                parentPort.postMessage({ type: "END", state: state });
            clearInterval(interval1);
        }

        //actualizar el estado del jugador 2
        if (!state.player2.isfallen)
        {
            state.player2.speed += state.player2.acceleration / 60;
            if (state.player2.speed > maxSpeed) 
                state.player2.speed = maxSpeed;
            else if (state.player2.speed < minSpeed)
                state.player2.speed = minSpeed;
            state.player2.distance += state.player2.speed / 60;
        }
        state.player2.time += 0.0166666666667;
        if (state.player2.distance >= 100)
        {
            if (state.winner === null) 
                state.winner = "player2";
            else
                parentPort.postMessage({ type: "END", state: state });
            clearInterval(interval1);
        }
        if ((last_footsp1.foot1 === last_footsp1.foot2) && (last_footsp1.foot1 !== null))
        {
            if (state.player1.speed > 4)
                state.player1.acceleration = -1 * state.player1.acceleration / 2;
            else
            {
                state.player1.isfallen = true;
                let interval2 = setInterval(() => {
                    state.player1.isfallen = false;
                    clearInterval(interval2);
                }, 1000);
            }
        }
        if ((last_footsp2.foot1 === last_footsp2.foot2) && (last_footsp2.foot1 !== null))
        {
            if (state.player2.speed > 4)
                state.player2.acceleration = -1 * state.player2.acceleration / 2;
            else
            {
                state.player2.isfallen = true;
                let interval2 = setInterval(() => {
                    state.player2.isfallen = false;
                    clearInterval(interval2);
                }, 1000);
            }
        }
        if (!state.player1.isfallen)
            state.player1.acceleration = calculateAcceleration(performance.now() - last_footsp1.time, state.player1.speed, maxSpeed);
        if (!state.player2.isfallen)
            state.player2.acceleration = calculateAcceleration(performance.now() - last_footsp2.time, state.player2.speed, maxSpeed);
        state.player1.last_step = last_footsp1.foot2 === null ? last_footsp1.foot1 : last_footsp1.foot2;
        state.player2.last_step = last_footsp2.foot2 === null ? last_footsp2.foot1 : last_footsp2.foot2;
        parentPort.postMessage({ type: "UPDATE", state: state });
    }, 16.6666666667 /* 60 FPS */);
}


module.exports = { SologameLogic };
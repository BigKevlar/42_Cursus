const { getRandomNumberInRange } = require('./utils.js');
const { parentPort } = require('worker_threads');

function AIgameLogic(state) {
    parentPort.on('message', (message) => {
        if (message.type === 'PADDLE_UPDATE') {
            state.paddles.left = message.left;
        }
        if (message.type === 'AI_UPDATE')
        {
            if (message.move > 0)
                state.paddles.right += 10;
            else if (message.move < 0)
                state.paddles.right -= 10;
        }
    });

    let ballismoving = true;
    let counter = 0;
    let interval = setInterval(() => {
        if (state.ball.dx < 1 && state.ball.dx > -1)
            state.ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        if (state.ball.dy < 1 && state.ball.dy > -1)
            state.ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        
        if (ballismoving) {
            state.ball.x += state.ball.dx;
            state.ball.y += state.ball.dy;
        }

        if (counter === 60) {
            counter = 0;
            let data = {ball: state.ball, id: state.id, paddle: state.paddles.right };
            try
            {
                fetch('http://ai:8080/updatestate', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json',
                    },
                    body: JSON.stringify(data),
                });
            }
            catch (error) { console.log(error); }
            
        }
        // Anotación de puntos
        if (state.ball.x >= 800) {
            state.score.left++;
            counter = 0;
            ballismoving = false;
            state.ball.x = 400;
            state.ball.y = 300;
            state.ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            state.ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            let fakeball = structuredClone(state.ball);
            fakeball.x = 380;
            fakeball.dx = 10;
            fakeball.dy = 0;
            let data = {ball: fakeball, id: state.id, paddle: state.paddles.right };
            try
            {
                fetch('http://ai:8080/updatestate', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json',
                    },
                    body: JSON.stringify(data),
                });
            }
            catch (error) { console.log(error); }
            let tempInterval = setInterval(() => {
                ballismoving = true;
                clearInterval(tempInterval);
                return;
            }, 1000);
        }
        else if (state.ball.x <= 0) {
            state.score.right++;
            counter = 0;
            ballismoving = false;
            state.ball.x = 400;
            state.ball.y = 300;
            state.ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            state.ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            let fakeball = structuredClone(state.ball);
            fakeball.x = 380;
            fakeball.dx = 10;
            fakeball.dy = 0;
            let data = {ball: fakeball, id: state.id, paddle: state.paddles.right };
            try
            {
                fetch('http://ai:8080/updatestate', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json',
                    },
                    body: JSON.stringify(data),
                });
            }
            catch (error) { console.log(error); }
            let tempInterval = setInterval(() => {
                ballismoving = true;
                clearInterval(tempInterval);
                return;
            }, 1000);
        }
        // Colisiones con los límites en Y
        if (state.ball.y <= 0) {
            state.ball.dy *= -1;
            state.ball.y = 1; // Ajusta la posición para sacarla de la pared superior
        } else if (state.ball.y >= 600) {
            state.ball.dy *= -1;
            state.ball.y = 599; // Ajusta la posición para sacarla de la pared inferior
        }
        

        // Colisión con paleta izquierda
        if ((state.ball.x >= 40 && state.ball.x <= 55)
            && (state.ball.y >= state.paddles.left - 50 && state.ball.y <= state.paddles.left + 50)) {
            state.ball.dx = getRandomNumberInRange(7, 12.5);
            state.ball.dy = (state.ball.y - state.paddles.left) / 10;
        }

        // Colisión con paleta derecha
        if ((state.ball.x >= 745 && state.ball.x <= 760)
            && (state.ball.y >= state.paddles.right - 50 && state.ball.y <= state.paddles.right + 50)) {
            state.ball.dx = getRandomNumberInRange(-7, -12.5);
            state.ball.dy = (state.ball.y - state.paddles.right) / 10;
        }

        // Verificar ganador
        if (state.score.left === 5 || state.score.right === 5) {
            state.winner = state.score.left === 5 ? 'left' : 'right';
            parentPort.postMessage({ type: 'UPDATE', state });
            parentPort.postMessage({ type: 'END', winner: state.winner });
            clearInterval(interval);
            return;
        }

        counter++;
        // Enviar el estado actualizado al proceso principal
        parentPort.postMessage({ type: 'UPDATE', state });
    }, 16);
}

module.exports =  { AIgameLogic };
const { getRandomNumberInRange } = require('./utils.js');
const { parentPort } = require('worker_threads');

function SologameLogic(state) {
    parentPort.on('message', (message) => {
        if (message.type === 'PADDLE_UPDATE') {
            state.paddles.right = message.right;
            state.paddles.left = message.left;
        }
    });

    let ballismoving = true;

    let interval = setInterval(() => {
        if (state.ball.dx < 1 && state.ball.dx > -1)
            state.ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        if (state.ball.dy < 1 && state.ball.dy > -1)
            state.ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        
        if (ballismoving) {
            state.ball.x += state.ball.dx;
            state.ball.y += state.ball.dy;
        }

        // Anotación de puntos
        if (state.ball.x >= 800) {
            state.score.left++;
            state.ball.x = 400;
            state.ball.y = 300;
            state.ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            state.ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            ballismoving = false;
            let tempInterval = setInterval(() => {
                ballismoving = true;
                clearInterval(tempInterval);
                return;
            }, 1000);
        }
        else if (state.ball.x <= 0) {
            state.score.right++;
            state.ball.x = 400;
            state.ball.y = 300;
            state.ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            state.ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
            ballismoving = false;
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

        // Enviar el estado actualizado al proceso principal
        parentPort.postMessage({ type: 'UPDATE', state });
    }, 16);
}

module.exports = { SologameLogic };
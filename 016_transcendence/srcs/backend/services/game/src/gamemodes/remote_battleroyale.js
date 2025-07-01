const { count } = require('console');
const { getRandomNumberInRange } = require('./utils.js');
const { parentPort } = require('worker_threads');

function scorePoints(ball, state) {
    if (ball.x >= 800) {
        state.score.right--;
        ball.x = 400;
        ball.y = 400;
        ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
    }
    else if (ball.x <= 0) {
        state.score.left--;
        ball.x = 400;
        ball.y = 400;
        ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
    }
    if (ball.y >= 800) {
        state.score.down--;
        ball.x = 400;
        ball.y = 400;
        ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
    }
    else if (ball.y <= 0) {
        state.score.up--;
        ball.x = 400;
        ball.y = 400;
        ball.dx = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
        ball.dy = getRandomNumberInRange(1, 2) === 1 ? getRandomNumberInRange(-10, -5) : getRandomNumberInRange(5, 10);
    }
}

function checkColl(ball, state) {
    // Colisiones con esquina superior izquierda (funcionando)
    if (ball.y <= 100 && ball.x <= 100) {
        if (ball.y < ball.x)
            ball.dx *= -1;
        else if (ball.y > ball.x)
            ball.dy *= -1;
        else if (state.paddlesLen.left !== 600 && state.paddlesLen.up !== 600) {
            ball.dx *= -1 + getRandomNumberInRange(-1, 1) / 10;
            ball.dy *= -1;
        }
    }
    // Esquina inferior izquierda (corregido)
    if (ball.y >= 700 && ball.x <= 100) {
        let distX = 100 - ball.x;     // distancia al borde vertical (positiva)
        let distY = ball.y - 700;     // distancia al borde horizontal (positiva)
        
        if (distY > distX) {
            // Si la distancia vertical es mayor, rebota horizontalmente
            ball.dx *= -1;
        } else if (distY < distX) {
            // Si la distancia horizontal es mayor, rebota verticalmente
            ball.dy *= -1;
        } else if (state.paddlesLen.left !== 600 && state.paddlesLen.down !== 600) {
            // Caso especial: rebote en ambas direcciones con factor aleatorio
            ball.dx *= -1 + getRandomNumberInRange(-1, 1) / 10;
            ball.dy *= -1;
        }
    }

    // Esquina superior derecha (corregido)
    if (ball.y <= 100 && ball.x >= 700) {
        let distX = ball.x - 700;     // distancia al borde vertical (positiva)
        let distY = 100 - ball.y;     // distancia al borde horizontal (positiva)

        if (distY > distX) {
            // Si la distancia vertical es mayor, rebota horizontalmente
            ball.dx *= -1;
        } else if (distY < distX) {
            // Si la distancia vertical es menor, rebota verticalmente
            ball.dy *= -1;
        } else if (state.paddlesLen.right !== 600 && state.paddlesLen.up !== 600); {
            // Rebote en ambas direcciones con factor aleatorio
            ball.dx *= -1 + getRandomNumberInRange(-1, 1) / 10;
            ball.dy *= -1;
        }
    }
    // Colisiones con esquina inferior derecha (funcionando)
    if (ball.y >= 700 && ball.x >= 700) {
        if (ball.y > ball.x)
            ball.dx *= -1;
        else if (ball.y < ball.x)
            ball.dy *= -1;
        else if (state.paddlesLen.right !== 600 && state.paddlesLen.down !== 600) {
            ball.dx *= -1 + getRandomNumberInRange(-1, 1) / 10;
            ball.dy *= -1;
        }
    }
}

function checkPaddleColl(ball, state) {
    // Colisión con paleta izquierda
    if (((ball.x >= 45 && ball.x <= 55) || (state.paddlesLen.left === 600 && ball.x <= 100))
        && (ball.y >= state.paddles.left - (state.paddlesLen.left / 2) && ball.y <= state.paddles.left + (state.paddlesLen.left / 2))) {
        if (state.paddlesLen.left !== 600) {
            ball.dx = getRandomNumberInRange(5, 10);
            ball.dy = (ball.y - state.paddles.left) / 10;
        }
        else if (ball.dx < 0)
            ball.dx *= -1;
    }

    // Colisión con paleta derecha
    if (((ball.x >= 745 && ball.x <= 755) || (state.paddlesLen.right === 600 && ball.x >= 700))
        && (ball.y >= state.paddles.right - (state.paddlesLen.right / 2) && ball.y <= state.paddles.right + (state.paddlesLen.right / 2))) {
        if (state.paddlesLen.right !== 600) {
            ball.dx = getRandomNumberInRange(-5, -10);
            ball.dy = (ball.y - state.paddles.right) / 10;
        }
        else if (ball.dx > 0)
            ball.dx *= -1;
    }

    //colision con la paleta inferior
    if (((ball.y >= 745 && ball.y <= 755) || (state.paddlesLen.down === 600 && ball.y >= 700))
        && (ball.x >= state.paddles.down - (state.paddlesLen.down / 2) && ball.x <= state.paddles.down + (state.paddlesLen.down / 2))) {
        if (state.paddlesLen.down !== 600) {
            ball.dy = getRandomNumberInRange(-5, -10);
            ball.dx = (ball.x - state.paddles.down) / 10;
        }
        else if (ball.dy > 0)
            ball.dy *= -1;
    }
    //colision con la paleta superior
    if (((ball.y >= 45 && ball.y <= 55) || (state.paddlesLen.up === 600 && ball.y <= 100))
        && (ball.x >= state.paddles.up - (state.paddlesLen.up / 2) && ball.x <= state.paddles.up + (state.paddlesLen.up / 2))) {
        if (state.paddlesLen.up !== 600) {
            ball.dy = getRandomNumberInRange(5, 10);
            ball.dx = (ball.x - state.paddles.up) / 10;
        }
        else if (ball.dy < 0)
            ball.dy *= -1;
    }
}

function RemoteMultiplayerGameLogic(state) {
    let connected = 1;

    parentPort.on('message', (message) => {
        if (message.type === 'RIGHT_PADDLE_UPDATE' && state.score.right > 0)
            state.paddles.right = message.right;
        else if (message.type === 'LEFT_PADDLE_UPDATE' && state.score.left > 0)
            state.paddles.left = message.left;
        else if (message.type === 'UP_PADDLE_UPDATE' && state.score.up > 0)
            state.paddles.up = message.up;
        else if (message.type === 'DOWN_PADDLE_UPDATE' && state.score.down > 0)
            state.paddles.down = message.down;
        else if (message.type === 'NEW PLAYER') {
            console.log('Nuevo jugador conectado');
            for (const player in state.playersNames) {
                if (state.playersNames[player] === null) {
                    state.playersNames[player] = message.name;
                    break;
                }
            }
            if (connected !== 4)
                connected++;
        }
        else if (message.type === 'PLAYER LEFT') {
            console.log(`El jugador ${message.player} se ha desconectado`);
            if (connected !== 4) {
                connected--;
                switch (message.player) {
                    case '1':
                        state.playerNames.left = null;
                        break;
                    case '2':
                        state.playerNames.right = null;
                        break;
                    case '3':
                        state.playerNames.up = null;
                        break;
                    case '4':
                        state.playerNames.down = null;
                        break;
            }
            }
            else {
                if (message.player === '1') state.score.left = 0;
                if (message.player === '2') state.score.right = 0;
                if (message.player === '3') state.score.up = 0;
                if (message.player === '4') state.score.down = 0;           
            }
        }
    });

    let interval1 = setInterval(() => {
        if (connected === 4) {
            console.log('Todos los jugadores han entrado');
            parentPort.postMessage({ type: 'READY' });
            clearInterval(interval1);
            return;
        }
        if (connected === 0) {
            parentPort.postMessage({ type: 'END', winner: null });
        }
    }, 8);

    let countdown = 4;
    let interval2 = setInterval(() => {
        if (countdown === 0) {
            clearInterval(interval2);
            return;
        }
        if (connected === 4)
            countdown--;
    }, 1000);

    let alive = 4;
    let interval = setInterval(() => {
        if (countdown === 0) {
            state.ball1.x += state.ball1.dx;
            state.ball1.y += state.ball1.dy;
            state.ball2.x += state.ball2.dx;
            state.ball2.y += state.ball2.dy;

            // Anotación de puntos
            scorePoints(state.ball1, state);
            scorePoints(state.ball2, state);
            // Colisiones con esquinas
            checkColl(state.ball1, state);
            checkColl(state.ball2, state);
            // Colisiones con las paletas
            checkPaddleColl(state.ball1, state);
            checkPaddleColl(state.ball2, state);
            // Verificar ganador y muertes
            if (state.score.left === 0 || state.score.right === 0 || state.score.up === 0 || state.score.down == 0) {
                alive--;
                if (state.score.left === 0) { state.score.left--; state.paddlesLen.left = 600; state.paddles.left = 400;}
                if (state.score.right === 0) { state.score.right--; state.paddlesLen.right = 600; state.paddles.right = 400;}
                if (state.score.up === 0) { state.score.up--; state.paddlesLen.up = 600; state.paddles.up = 400;}
                if (state.score.down === 0) { state.score.down--; state.paddlesLen.down = 600; state.paddles.down = 400;}
                if (alive === 1) {
                    if (state.score.left > 0) state.winner = 'left';
                    if (state.score.right > 0) state.winner = 'right';
                    if (state.score.up > 0) state.winner = 'up';
                    if (state.score.down > 0) state.winner = 'down';
                    parentPort.postMessage({ type: 'UPDATE', state });
                    parentPort.postMessage({ type: 'END', winner: state.winner });
                    clearInterval(interval);
                    return;
                }
                parentPort.postMessage({ type: 'UPDATE', state });
            }

            // Enviar el estado actualizado al proceso principal
            parentPort.postMessage({ type: 'UPDATE', state });
        }
    }, 16);
}

module.exports = { RemoteMultiplayerGameLogic };
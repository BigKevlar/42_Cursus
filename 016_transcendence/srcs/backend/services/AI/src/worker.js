import { parentPort } from 'worker_threads';

function raycasting(ball) {
    if (ball === undefined)
        return -1;
    
    let ballX = ball.x;
    let ballY = ball.y;
    let dX = ball.dx;
    let dY = ball.dy;

    while ((ballX >= 50 && ballX <= 750)) {
        ballX += dX;
        ballY += dY;
        if (ballY <= 0 || ballY >= 600)
            dY *= -1;
    }
    return ballY;
}





function create_newAI(id) {
    let AIObj;
    let paddle;
    let ball;
    let inactivityTimeout;

    function resetInactivityTimeout() {
        clearTimeout(inactivityTimeout);
        inactivityTimeout = setTimeout(() => {
            console.log(`Worker ${id} inactivo. Terminando...`);
            process.exit(0);
        }, 10000);
    }

    parentPort.on('message', (message) => {
        if (message.type === 'UPDATE BALL')
        {
            resetInactivityTimeout(inactivityTimeout, id);
            ball = message.ball;
            paddle = message.paddle;
        }
    });
    setInterval( () => {
        AIObj = raycasting(ball);

        if (AIObj !== -1)
        {
            if (AIObj >= paddle + 40) {
                fetch('http://game:8080/move', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json', 
                    },
                    body: JSON.stringify({id: id, pos: 1})
                });
                paddle += 10;
            }
            if (AIObj <= paddle - 40) {
                fetch('http://game:8080/move', {
                    method: 'POST',
                    headers: {
                        'Content-Type': 'application/json', 
                    },
                    body: JSON.stringify({id: id, pos: -1})
                });
                paddle -= 10; 
            }
        }
    }, 16);
}

parentPort.on('message', (message) => {
    if (message.type === 'NEW GAME') {
        console.log('🎮 AI init');
        create_newAI(message.id);
    }
});

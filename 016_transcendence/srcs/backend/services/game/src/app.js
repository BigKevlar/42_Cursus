const Fastify = require('fastify');
const { WebSocketServer } = require('ws');
const { Worker } = require('worker_threads');
const { createServer } = require('http');
const { getRandomNumberInRange } = require('./gamemodes/utils.js');

const server = createServer();
const wss = new WebSocketServer({ server });

const PORT = process.env.PORT || 8080;

// Configurar Fastify para usar el servidor HTTP existente
const fastifyConfig = {
    logger: false,
    serverFactory: (handler) => {
        server.on('request', handler);
        return server;
    }
};

const fastify = Fastify(fastifyConfig);
fastify.register(require('./routes/health.js'));

let games = new Map();
let id = 0;

fastify.post('/move' ,  async (request, reply) => {
	const { id, pos } = request.body;
	const worker = games.get(id).worker;
	worker.postMessage( { type: 'AI_UPDATE', move: pos } );
	reply.send('OK!')
});

function handleMultiPaddles(id, worker) {
	let game = games.get(id).state;
	let ws = games.get(id).ws;
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'r-up' && game.paddles.right >= 150) {
			game.paddles.right -= 10;
		}
		else if (parsedMessage === 'r-down' && game.paddles.right <= 650) {
			game.paddles.right += 10;
		}
		else if (parsedMessage === 'l-up' && game.paddles.left >= 150) {
			game.paddles.left -= 10;
		}
		else if (parsedMessage === 'l-down' && game.paddles.left <= 650) {
			game.paddles.left += 10;
		}
		else if (parsedMessage === 'u-right' && game.paddles.up <= 650) {
			game.paddles.up += 10;
		}
		else if (parsedMessage === 'u-left' && game.paddles.up >= 150) {
			game.paddles.up -= 10;
		}
		else if (parsedMessage === 'd-right' && game.paddles.down <= 650) {
			game.paddles.down += 10;
		}
		else if (parsedMessage === 'd-left' && game.paddles.down >= 150) {
			game.paddles.down -= 10;
		}
		worker.postMessage({ type: 'PADDLE_UPDATE MULTI', left: game.paddles.left, right: game.paddles.right, up: game.paddles.up, down: game.paddles.down });
	});
}

function handlePaddles(id, worker) {
	let game = games.get(id).state;
	let ws = games.get(id).ws;
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'r-up' && game.paddles.right >= 50) {
			game.paddles.right -= 10;
		}
		else if (parsedMessage === 'r-down' && game.paddles.right <= 550) {
			game.paddles.right += 10;
		}
		else if (parsedMessage === 'l-up' && game.paddles.left >= 50) {
			game.paddles.left -= 10;
		}
		else if (parsedMessage === 'l-down' && game.paddles.left <= 550) {
			game.paddles.left += 10;
		}
		worker.postMessage({ type: 'PADDLE_UPDATE', left: game.paddles.left, right: game.paddles.right });
	});
}

//jugador 2 paleta izquierda
function handleleftPaddle(id, worker, mode = 0) {
	let game = games.get(id).state;
	let ws = games.get(id).ws2;
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'up' && game.paddles.left >= 50 + mode) {
			game.paddles.left -= 10;
		}
		else if (parsedMessage === 'down' && game.paddles.left <= 550 + mode) {
			game.paddles.left += 10;
		}
		worker.postMessage({ type: 'LEFT_PADDLE_UPDATE', left: game.paddles.left });
	});
}
//jugador 1 paleta derecha
function handlerightPaddle(id, worker, mode = 0) {
	let game = games.get(id).state;
	let ws = games.get(id).ws1;
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'up' && game.paddles.right >= 50 + mode) {
			game.paddles.right -= 10;
		}
		else if (parsedMessage === 'down' && game.paddles.right <= 550 + mode) {
			game.paddles.right += 10;
		}
		worker.postMessage({ type: 'RIGHT_PADDLE_UPDATE', right: game.paddles.right });
	});
}

//jugador 3 paleta arriba
function handleUpPaddle(id, worker) {
	let game = games.get(id).state;
	let ws = games.get(id).ws3;
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'left' && game.paddles.up >= 150) {
			game.paddles.up -= 10;
		}
		else if (parsedMessage === 'right' && game.paddles.up <= 650) {
			game.paddles.up += 10;
		}
		worker.postMessage({ type: 'UP_PADDLE_UPDATE', up: game.paddles.up });
	});
}

//juagador 4 paleta abajo
function handleDownPaddle(id, worker) {
	let game = games.get(id).state;
	let ws = games.get(id).ws4;
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'left' && game.paddles.down >= 150) {
			game.paddles.down -= 10;
		}
		else if (parsedMessage === 'right' && game.paddles.down <= 650) {
			game.paddles.down += 10;
		}
		worker.postMessage({ type: 'DOWN_PADDLE_UPDATE', down: game.paddles.down });
	});
}


function startGame(id, name = null) {
  return {
    id: id,
    ball: { x: 400, y: 300, dx: getRandomNumberInRange(-5, 5), dy: getRandomNumberInRange(-5, 5) }, // Posición y dirección de la bola
    paddles: { 
      left: 300 ,
      right:300
    },
	paddlesLen: { 
		left: 100 ,                      
		right:100                     
	},
	playersNames: {
		left: name,
		right: null
	},
    score: { left: 0, right: 0 },           
	winner: null
};
}

function startMultiGame(id, name = null) {
	return {
	  id: id,
	  ball1: { x: 400, y: 400, dx: getRandomNumberInRange(-5, 5), dy: getRandomNumberInRange(-5, 5) }, // Posición y dirección de la bola
	  ball2: { x: 400, y: 400, dx: getRandomNumberInRange(-5, 5), dy: getRandomNumberInRange(-5, 5) },
	  paddles: { 
		left: 400 ,
		right:400 ,
		up:   400 ,
		down: 400
	},
	paddlesLen: { 
		left: 100 ,                      
		right:100 ,                     
		up:   100 ,
		down: 100
	},
	playersNames: {
		left: name,
		right: null,
		up: null,
		down: null
	},
	  score: { left: 10, right: 10, up: 10, down: 10 },             // Marcador inicial
	  winner: null
  };
  }

wss.on('connection', (ws) => {
	console.log('🎮 Nuevo jugador conectado');

	ws.on('message', (message) => {
		try
		{
			const parsedMessage = JSON.parse(message);	
			if (parsedMessage.mode === 'new solo-game') {
				const worker = new Worker('./worker.js');
				const actualId = id++;
				games.set(actualId, { type: 'solo-game', worker: worker, ws: ws, state: startGame(actualId) });
				worker.postMessage({ type: 'START SOLO-GAME', state: games.get(actualId).state});
				handlePaddles(actualId, worker);
				worker.on('message', (message) => {
					if (message.type === 'UPDATE') {
						sendto(actualId, JSON.stringify(message.state)); // Envía estado actualizado al cliente
					} else if (message.type === 'END') {
						console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
						worker.terminate();
						games.delete(actualId);
					}
				});
			}
			else if (parsedMessage.mode === 'new AI-game') {
				const worker = new Worker('./worker.js');
				const actualId = id++;
				games.set(actualId, { type: 'AI-game', worker: worker, ws: ws, state: startGame(actualId) });
				worker.postMessage({ type: 'START AI-GAME', state: games.get(actualId).state});
				handlePaddles(actualId, worker);
				worker.on('message', (message) => {
					if (message.type === 'UPDATE') {
						sendto(actualId, JSON.stringify(message.state)); // Envía estado actualizado al cliente
					} else if (message.type === 'END') {
						console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
						worker.terminate();
						games.delete(actualId);
					}
				});
			}
			else if (parsedMessage.mode === 'new remote-game') {
				for (const key of games.keys()) {
					if (games.get(key).type === 'remote-game' && games.get(key).ws2 === undefined) {
						games.get(key).ws2 = ws;
						games.get(key).worker.postMessage({ type: 'NEW PLAYER', name: parsedMessage.name });
						handleleftPaddle(key, games.get(key).worker);
						handlerightPaddle(key, games.get(key).worker);
						return;
					}
				}
				
				const worker = new Worker('./worker.js');
				const actualId = id++;
				games.set(actualId, { type: 'remote-game', worker: worker, ws1: ws, ws2: undefined, state: startGame(actualId, parsedMessage.name) });
				worker.postMessage({ type: 'START REMOTE-GAME', state: games.get(actualId).state});
				worker.on('message', (message) => {
					if (message.type === 'UPDATE') {
						sendto(actualId, JSON.stringify(message.state));
					} else if (message.type === 'END') {
						console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
						worker.terminate();
					} else if (message.type === 'READY') {
						sendto(actualId, JSON.stringify('ready'));
					}
				});
				ws.on('close', () => {
					console.log('🚪 Jugador desconectado');
					const game = games.get(actualId);
					if (game && game.ws2 === undefined) {
						worker.postMessage({ type: 'PLAYER LEFT', player: ws === game.ws1 ? '1' : '2' });
						let issleeping = true;
						let sleep = setInterval(() => {
							issleeping = false;
							clearInterval(sleep);
						}, 1000);
						if (!issleeping) {
							game.worker.terminate();
							games.delete(actualId);
							if (game.ws1 !== ws) {
								game.ws1.send('Jugador 2 desconectado');
							}
							else game.ws2.send('Jugador 1 desconectado');
						}
					}
					else if (game && game.ws2 !== undefined) {
						worker.postMessage({ type: 'PLAYER LEFT', player: ws === game.ws1 ? '1' : '2' });
						let issleeping = true;
						let sleep = setInterval(() => {
							issleeping = false;
							clearInterval(sleep);
						}, 1000);
						if (!issleeping) {
							game.worker.terminate();
							games.delete(actualId);
							if (game.ws1 !== ws) {
								game.ws1.send('Jugador 2 desconectado');
							}
							else game.ws2.send('Jugador 1 desconectado');
						}
					}
				});
			}
			else if (parsedMessage.mode === 'new multiplayer-game (local)') {
				const worker = new Worker('./worker.js');
				const actualId = id++;
				games.set(actualId, {type: 'localMultiplayer-game', worker: worker, ws: ws, state: startMultiGame(actualId) });
				worker.postMessage({ type: 'MULTIPLAYER LOCAL-GAME', state: games.get(actualId).state});
				handleMultiPaddles(actualId, worker);
				worker.on('message', (message) => {
					if (message.type === 'UPDATE') {
						sendto(actualId, JSON.stringify(message.state));
					} else if (message.type === 'END') {
						console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
						worker.terminate();
						games.delete(actualId);
					}
				});
			}
			else if (parsedMessage.mode === 'new multiplayer-game (remote)') {
				console.log('Conectando a un nuevo jugador remoto');
				for (const key of games.keys()) {
					if (games.get(key).type === 'remoteMultiplayer-game' && (games.get(key).ws2 === undefined || games.get(key).ws3 === undefined || games.get(key).ws4 === undefined)) {
						if (games.get(key).ws2 === undefined)
							games.get(key).ws2 = ws;
						else if (games.get(key).ws3 === undefined)
							games.get(key).ws3 = ws;
						else if (games.get(key).ws4 === undefined)
							games.get(key).ws4 = ws;
						games.get(key).worker.postMessage({ type: 'NEW PLAYER', name: parsedMessage.name });
						if (games.get(key).ws2 !== undefined && games.get(key).ws3 !== undefined && games.get(key).ws4 !== undefined) {
							handleleftPaddle(key, games.get(key).worker, 100);
							handlerightPaddle(key, games.get(key).worker, 100);
							handleUpPaddle(key, games.get(key).worker);
							handleDownPaddle(key, games.get(key).worker);
						}
						return;
					}
				}
				
				
				const worker = new Worker('./worker.js');
				const actualId = id++;
				games.set(actualId, { type: 'remoteMultiplayer-game', worker: worker, ws1: ws, ws2: undefined, ws3: undefined, ws4: undefined, state: startMultiGame(actualId, parsedMessage.name) });
				worker.postMessage({ type: 'MULTIPLAYER REMOTE-GAME', state: games.get(actualId).state});
				worker.on('message', (message) => {
					if (message.type === 'UPDATE') {
						sendto(actualId, JSON.stringify(message.state)); // Envía estado actualizado al cliente
					} else if (message.type === 'END') {
						console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
						worker.terminate();
						games.delete(actualId);
					} else if (message.type === 'READY') {
						sendto(actualId, JSON.stringify('ready'));
					}
				});
				ws.on('close', () => {
					console.log('🚪 Jugador desconectado');
					const game = games.get(actualId);
					if (worker && game)
						worker.postMessage({ type: 'PLAYER LEFT', player: game.ws1 === ws ? '1' : game.ws2 === ws ? '2' : game.ws3 === ws ? '3' : '4' });
				});
			}
			else if (parsedMessage.mode === 'new tournament-game') {
				const worker = new Worker('./worker.js');
				const actualId = id++;
				games.set(actualId, { type: 'tournament-game', worker: worker, ws: ws, state: startGame(actualId) });
				worker.postMessage({ type: 'START SOLO-GAME', state: games.get(actualId).state});
				handlePaddles(actualId, worker);
				worker.on('message', (message) => {
					if (message.type === 'UPDATE') {
						sendto(actualId, JSON.stringify(message.state)); // Envía estado actualizado al cliente
					} else if (message.type === 'END') {
						console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
						try {
							fetch('http://tournament:8080/setresult', {
								method: 'POST',
								headers: {
									'Content-Type': 'application/json',
								},
								body: JSON.stringify({ result: {side: parsedMessage.datamatch.side, round: parsedMessage.datamatch.round,
									match: parsedMessage.datamatch.match, winner: message.winner, id: parsedMessage.datamatch.id} }),
							});
						}
						catch (error) { console.log(error); }
						worker.terminate();
						games.delete(actualId);
					}
				});
			}
		}
		catch (err) { }
	});
});

function sendto(clientid, state) {
	if (games.get(clientid).type === 'remote-game' && games.get(clientid).ws2 !== undefined) {
		if (games.get(clientid).ws1 !== undefined)
			games.get(clientid).ws1.send(state);
		if (games.get(clientid).ws2 !== undefined)
			games.get(clientid).ws2.send(state);
	}
	else if (games.get(clientid).type === 'remoteMultiplayer-game') {
		try {
			if (games.get(clientid).ws1 !== undefined)
				games.get(clientid).ws1.send(state);
			if (games.get(clientid).ws2 !== undefined)
				games.get(clientid).ws2.send(state);
			if (games.get(clientid).ws3 !== undefined)
				games.get(clientid).ws3.send(state);
			if (games.get(clientid).ws4 !== undefined)
				games.get(clientid).ws4.send(state);
		}
		catch (err) { console.log(err); }
		
	}
	else
	{
		if (games.get(clientid).ws !== undefined)
			games.get(clientid).ws.send(state);
		games.get(clientid).ws.send(state)
	}
}


server.listen(PORT, () => {
	console.log(`🚀 Servidor WebSocket y HTTP corriendo en puerto ${PORT}`);
});

fastify.ready((err) => {
    if (err) {
        console.error("Error al iniciar Fastify:", err);
        process.exit(1);
    }
});

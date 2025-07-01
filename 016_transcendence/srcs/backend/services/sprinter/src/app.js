const Fastify = require('fastify');
const { WebSocketServer } = require('ws');
const { Worker } = require('worker_threads');
const { createServer } = require('http');

const server = createServer();
const wss = new WebSocketServer({ server });

const PORT = process.env.PORT || 8080;

// Configurar Fastify para usar el servidor HTTP existente
const fastifyConfig = {
    logger: true,
    serverFactory: (handler) => {
        server.on('request', handler);
        return server;
    }
};

const fastify = Fastify(fastifyConfig);
fastify.register(require('./routes/health.js'));

let games = new Map();

function startGame(id) {
	const state = {
		id: id,
		player1: { distance: 0.5 /* m */, speed: 0 /* m/s */, acceleration: 0 /* m/s ^ 2 */, time: 0 /* s */, last_step: null, isfallen: false },
		player2: { distance: 0, speed: 0, acceleration: 0, time: 0, last_step: null, isfallen: false },
		winner: null,
	};
	return state;
}

function handleKeys(ws, worker) {
	ws.on('message', (message) => {
		const parsedMessage = message.toString();

		if (parsedMessage === 'p1-left')
			worker.postMessage({ type: 'p1-left' });
		else if (parsedMessage === 'p1-right')
			worker.postMessage({ type: 'p1-right' });
		else if (parsedMessage === 'p2-left')
			worker.postMessage({ type: 'p2-left' });
		else if (parsedMessage === 'p2-right')
			worker.postMessage({ type: 'p2-right' });
	});
}


wss.on('connection', (ws) => {
	console.log('🎮 Nuevo jugador conectado');
  
	ws.on('message', (message) => {
		const parsedMessage = message.toString();
		if (parsedMessage === 'new solo-game') {
			const worker = new Worker('./worker.js');
		const actualId = games.size;
		games.set(actualId, { type: 'solo-game', worker: worker, ws: ws, state: startGame(actualId) });
		worker.postMessage({ type: 'START SOLO-GAME', state: games.get(actualId).state});
		handleKeys(ws, worker);
		worker.on('message', (message) => {
			if (message.type === 'UPDATE') {
				sendto(actualId, JSON.stringify(message.state)); // Envía estado actualizado al cliente
		  	} 
		  	else if (message.type === 'END') {
				console.log(`🏆 Ganador de la partida ${actualId}: ${message.winner}`);
				worker.terminate();
				games.delete(actualId);
		  	}
		});
	  }
	});
  });

server.listen(PORT, () => {
	console.log(`🚀 Servidor WebSocket y HTTP corriendo en puerto ${PORT}`);
});

// Inicializar Fastify después de que el servidor esté escuchando
fastify.ready((err) => {
    if (err) {
        console.error("Error al iniciar Fastify:", err);
        process.exit(1);
    }
});


function sendto(clientid, state) {
	if (!games.get(clientid)) return;
	if (games.get(clientid).type === 'solo-game') {
		games.get(clientid).ws.send(state)
	}
}
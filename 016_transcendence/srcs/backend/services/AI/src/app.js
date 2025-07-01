import Fastify from 'fastify';
import { Worker } from 'worker_threads';

let workers = new Map(); 

const PORT = process.env.PORT || 8080;

const fastify = Fastify({ logger: false });

fastify.listen({ port: PORT, host: '0.0.0.0' }, (err, address) => {
    if (err) {
        console.error(err);
        process.exit(1);
    }
	console.log(`🚀 Servidor IA corriendo en puerto ${address}`);
  });

fastify.get('/status', async (request, reply) => {
    reply.send('OK42');
});

fastify.post('/newgame',  async (request, reply) => {
    const { id } = request.body;
    const worker = new Worker('./worker.js', { type: 'module' });
    workers.set(id, worker);
	worker.postMessage( { type: 'NEW GAME', id: id });
    console.log(`NUEVA IA ${id}`);
	reply.send({ status: 'ok' });
});

fastify.post('/updatestate',  async (request, reply) => {
    const { id, ball, paddle } = request.body;
    let worker = workers.get(id);
	worker.postMessage( { type: 'UPDATE BALL', ball: ball, paddle: paddle});
    reply.send({ status: 'ok' });
});

const { parentPort } = require('worker_threads');
const { SologameLogic } = require('./gamemodes/sologame.js');

parentPort.on('message', (message) => {
    if (message.type === 'START SOLO-GAME') {
        let gameState = message.state;
        console.log('🎮 Juego iniciado (solo) en Worker con estado:', gameState);
        SologameLogic(gameState);
    }
});

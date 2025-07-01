const { parentPort } = require('worker_threads');
const { SologameLogic } = require('./gamemodes/pvp.js');
const { AIgameLogic } = require('./gamemodes/ai.js');
const { localMultiplayerGameLogic } = require('./gamemodes/battleroyale.js');
const { RemotegameLogic } = require('./gamemodes/remote.js');
const { RemoteMultiplayerGameLogic } = require('./gamemodes/remote_battleroyale.js');


// Manejar mensajes desde el proceso principal
parentPort.on('message', (message) => {
    if (message.type === 'START SOLO-GAME') {
        let gameState = message.state;
        console.log('🎮 Juego iniciado (solo) en Worker con estado:', gameState);
        SologameLogic(gameState);
    }
    else if (message.type === 'START AI-GAME') {
        let gameState = message.state;
        console.log('🎮 Juego iniciado (AI) en Worker con estado:', gameState);
        try
        {
            fetch('http://ai:8080/newgame', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ id: gameState.id }),
            });
        }
        catch (error) { console.log(error); }
        AIgameLogic(gameState);
    }
    else if (message.type === 'MULTIPLAYER LOCAL-GAME') {
        let gameState = message.state;
        console.log('🎮 Juego iniciado (multiplayer local) en Worker con estado:', gameState);
        localMultiplayerGameLogic(gameState);
    }
    else if (message.type === 'START REMOTE-GAME') {
        let gameState = message.state;
        console.log('🎮 Juego iniciado (esperando a otro jugador) (remoto) en Worker con estado:', gameState);
        RemotegameLogic(gameState);
    }
    else if (message.type === 'MULTIPLAYER REMOTE-GAME') {
        let gameState = message.state;
        console.log('🎮 Juego iniciado (esperando a los demas jugadores) (multiplayer) en Worker con estado:', gameState);
        RemoteMultiplayerGameLogic(gameState);
    }
});

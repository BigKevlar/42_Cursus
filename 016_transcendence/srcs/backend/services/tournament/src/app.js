const fastify = require('fastify');

const app = fastify({ logger: false });
app.register(require('./routes/health.js'));

const PORT = process.env.PORT || 8080;

let actualId = 0;
let tournaments = new Map();

/*JSON QUE ME DEBERIA DE LLEGAR
players = {
	p1: nombre_del_jugador
	p2: nombre_del_jugador
	p3: nombre_del_jugador
	p4: nombre_del_jugador
	p5: nombre_del_jugador
	p6: nombre_del_jugador
	p7: nombre_del_jugador
	p8: nombre_del_jugador

	hasta 4 si es de 4, hasta 8 si es de 8 y hasta 16 si es de 16
}

*/

function randomPlayer(players) {
	const definiedKeys = Object.keys(players).filter(key => players[key] !== undefined);
	const player = definiedKeys[Math.floor(Math.random() * definiedKeys.length)];
	const playername = players[player];
	players[player] = undefined;
	return (playername);
}


function setPlayerInNextRound(bracket, winner) {
    // 1. Encontrar dónde está el ganador actualmente (SOLO en la última ronda que ganó)
    let currentRound = null;
    let currentSide = null;
    let currentMatch = null;
    let maxRound = 0;

    // Buscar en cada ronda - nos quedamos con la ocurrencia en la ronda más alta
    for (const roundKey in bracket) {
        if (roundKey === "id" || roundKey === "nextmatch") continue;
        
        const roundObj = bracket[roundKey];
        const roundNum = parseInt(roundKey.replace("round", ""));
        
        // Revisar si es la final
        if (roundObj.final && roundObj.final.winner === winner) {
            // Si el ganador ya está en la final, no hay más rondas
            return;
        }
        
        // Revisar cada lado (izquierdo/derecho)
        for (const side in roundObj) {
            if (side === "final") continue;
            
            // Revisar cada partido en este lado
            for (const matchKey in roundObj[side]) {
                const match = roundObj[side][matchKey];
                
                // Si este partido tiene al ganador Y es de una ronda mayor
                if (match.winner === winner && roundNum > maxRound) {
                    currentRound = roundNum;
                    currentSide = side;
                    currentMatch = matchKey;
                    maxRound = roundNum;
                    // No salimos inmediatamente, seguimos buscando en rondas superiores
                }
            }
        }
    }
    
    // Si no encontramos al ganador, salir
    if (currentRound === null) {
        console.log(`No se encontró al ganador ${winner} en ningún partido`);
        return;
    }
    
    // 2. Determinar la siguiente ronda
    const nextRoundKey = `round${currentRound + 1}`;
    if (!bracket[nextRoundKey]) {
        console.log(`No hay siguiente ronda después de round${currentRound}`);
        return;
    }
    
    console.log(`Avanzando a ${winner} desde round${currentRound} hacia ${nextRoundKey}`);
    
    // 3. Colocar al ganador en la siguiente ronda
    if (bracket[nextRoundKey].final) {
        // Si la siguiente ronda es la final
        if (currentSide === "left") {
            console.log(`Colocando a ${winner} como p1 en la final`);
            bracket[nextRoundKey].final.p1 = winner;
        } else {
            console.log(`Colocando a ${winner} como p2 en la final`);
            bracket[nextRoundKey].final.p2 = winner;
        }
    } else {
        // Calcular en qué partido de la siguiente ronda debe ir el ganador
        const matchNumber = parseInt(currentMatch.replace("match", ""));
        const nextMatchNumber = Math.ceil(matchNumber / 2);
        const nextMatchKey = `match${nextMatchNumber}`;
        
        // Determinar si es p1 o p2 en el siguiente partido
        const isP1 = matchNumber % 2 === 1;
        const position = isP1 ? "p1" : "p2";
        
        console.log(`Colocando a ${winner} como ${position} en ${nextRoundKey}.${currentSide}.${nextMatchKey}`);
        
        // Asegurarse de que la estructura exista
        if (!bracket[nextRoundKey][currentSide]) {
            console.error(`Error: No existe la estructura ${nextRoundKey}.${currentSide}`);
            return;
        }
        
        if (!bracket[nextRoundKey][currentSide][nextMatchKey]) {
            console.error(`Error: No existe la estructura ${nextRoundKey}.${currentSide}.${nextMatchKey}`);
            return;
        }
        
        // Colocar al ganador en la siguiente ronda
        bracket[nextRoundKey][currentSide][nextMatchKey][position] = winner;
    }
}

function randomMatch(bracket) {
    let validMatches = [];

    for (const round of Object.keys(bracket)) {
        if (round === "id" || round === "nextmatch") continue;

        const roundData = bracket[round];

        for (const side of Object.keys(roundData)) {
            const sideData = roundData[side];

            for (const match of Object.keys(sideData)) {
                const matchData = sideData[match];

                if (matchData &&
                    matchData.p1 !== undefined &&
                    matchData.p2 !== undefined &&
                    matchData.winner === undefined
                ) {
                    validMatches.push({
                        round: round,
                        side: side,
                        match: match,
                        p1: matchData.p1,
                        p2: matchData.p2
                    });
                }
            }
        }
    }

    if (validMatches.length === 0) return undefined;

    // Selecciona un match aleatorio y devuelve el JSON correspondiente
    return validMatches[Math.floor(Math.random() * validMatches.length)];
}

/*EL JSON RESULT DEBERIA DE TENER ESTA ESTRUCTURA:
	result = {
		side: el lado del bracket / final
		round: la ronda en la que se juagaba el partido round1/round2/round3 (si es final dejarlo en nulo)
		match: match1/match2 el que sea
		winner: el nombre del ganador
	};
*/
function postResult(id, result) {
	let bracket = tournaments.get(parseInt(id));
	if (!bracket) {
		console.error(`Error: No se encontró el torneo con ID ${id}`);
		return;
	}

	let winnername;
	console.log(result.side);
	
	if (result.side === 'final') {
        winnername = result.winner === 'left' ? bracket[result.round].final.p1 : bracket[result.round].final.p2;
		bracket[result.round].final.winner = winnername;
		bracket.nextmatch = null;
	}
    else {
        winnername = result.winner === 'left' ? bracket[result.round][result.side][result.match].p1 : bracket[result.round][result.side][result.match].p2;
		bracket[result.round][result.side][result.match].winner = winnername;
		setPlayerInNextRound(bracket, winnername);
		
		// Intentar encontrar el siguiente partido
		bracket.nextmatch = randomMatch(bracket);
		
		// Si no se encontró ningún partido, verificar si podemos jugar la final
		if (bracket.nextmatch === undefined) {
			// Determinar cuál es la ronda que contiene la final según el tamaño del torneo
			let finalRound;
			
			// Para torneos de 4 jugadores, la final está en round2
			if (bracket.round3 === undefined) {
				finalRound = 'round2';
			} 
			// Para torneos de 8 jugadores, la final está en round3
			else if (bracket.round4 === undefined) {
				finalRound = 'round3';
			} 
			// Para torneos de 16 jugadores, la final está en round4
			else {
				finalRound = 'round4';
			}
			
			console.log(`Determinado que la final está en ${finalRound}`);
			
			// Verificar que la estructura exista y tenga los valores necesarios
			if (bracket[finalRound] && bracket[finalRound]['final']) {
				const p1 = bracket[finalRound]['final'].p1;
				const p2 = bracket[finalRound]['final'].p2;
				
				// Solo crear el nextmatch para la final si ambos jugadores están definidos
				if (p1 !== undefined && p2 !== undefined) {
					console.log(`Final entre ${p1} y ${p2}`);
					bracket.nextmatch = {
						match: null, 
						side: 'final', 
						round: finalRound, 
						p1: p1, 
						p2: p2
					};
				} else {
					// Si no podemos jugar la final, intentar buscar otro partido disponible
					console.log(`Aún no se puede jugar la final. Jugador 1: ${p1 || 'No definido'}, Jugador 2: ${p2 || 'No definido'}`);
					console.log("Buscando otros partidos disponibles...");
					
					// Buscar partidos en todas las rondas y lados que tengan los jugadores definidos pero no un ganador
					let validMatches = [];
					for (const round of Object.keys(bracket)) {
						if (round === "id" || round === "nextmatch") continue;
						
						const roundData = bracket[round];
						
						for (const side of Object.keys(roundData)) {
							if (side === "final") continue;
							
							const sideData = roundData[side];
							
							for (const match of Object.keys(sideData)) {
								const matchData = sideData[match];
								
								if (matchData && 
									matchData.p1 !== undefined && 
									matchData.p2 !== undefined && 
									matchData.winner === undefined) {
									validMatches.push({
										round: round,
										side: side,
										match: match,
										p1: matchData.p1,
										p2: matchData.p2
									});
								}
							}
						}
					}
					
					if (validMatches.length > 0) {
						// Seleccionar un partido aleatorio de los disponibles
						bracket.nextmatch = validMatches[Math.floor(Math.random() * validMatches.length)];
						console.log(`Partido encontrado: ${bracket.nextmatch.round}, ${bracket.nextmatch.side}, ${bracket.nextmatch.match} entre ${bracket.nextmatch.p1} y ${bracket.nextmatch.p2}`);
					} else {
						console.log("No hay más partidos disponibles. Esperando a que los jugadores avancen a la final.");
						bracket.nextmatch = null; 
					}
				}
			} else {
				console.error(`Error: La estructura bracket[${finalRound}]['final'] no está definida`);
				bracket.nextmatch = null;
			}
		}
	}
}

function createBrackets(numofplayers, players, id) {
	if (numofplayers === 4) {
		return ({
			id: id,
			nextmatch: undefined,
			round1:
			{
				left: { match1: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }},
				right: { match1: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }}
			},
			round2:
			{
				final: { p1: undefined, p2: undefined, winner: undefined }
			}
		});
	}
	else if (numofplayers === 8) {
		return ({
			id: id,
			nextmatch: undefined,
			round1:
			{
				left: { match1: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match2: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }},
				right: { match1: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match2: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }}
			},
			round2:
			{
				left: { match1: { p1: undefined, p2: undefined, winner: undefined }},
				right: { match1: { p1: undefined, p2: undefined, winner: undefined }}
			},
			round3:
			{
				final: { p1: undefined, p2: undefined, winner: undefined }
			}
		});
	}
	else if (numofplayers === 16) {
		return ({
			id: id,
			nextmatch: undefined,
			round1:
			{
				left: { match1: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match2: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match3: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match4: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }},
				right: { match1: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match2: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match3: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }, match4: { p1: randomPlayer(players), p2: randomPlayer(players), winner: undefined }}
			},
			round2:
			{
				left: { match1: { p1: undefined, p2: undefined, winner: undefined }, match2: { p1: undefined, p2: undefined, winner: undefined }},
				right: { match1: { p1: undefined, p2: undefined, winner: undefined }, match2: { p1: undefined, p2: undefined, winner: undefined }}
			},
			round3:
			{
				left: { match1: { p1: undefined, p2: undefined, winner: undefined }},
				right: { match1: { p1: undefined, p2: undefined, winner: undefined }}
			},
			round4:
			{
				final: { p1: undefined, p2: undefined, winner: undefined }
			}
		});
	}
}
function createTournament(players, numofplayers) {
	if (numofplayers != 16 && numofplayers != 8 && numofplayers != 4)
		return false;
	tournaments.set(actualId, createBrackets(numofplayers, players, actualId++));
	tournaments.get(actualId - 1).nextmatch = randomMatch(tournaments.get(actualId - 1));
	return true;
}

app.post('/create', (req, reply) => {

	const {numofplayers, players} = req.body;
	if (!createTournament(players, numofplayers))
		reply.send({status: 'error', error: 'number of players is incorrect or any player name is undefined'})
	else
		reply.send({status: 'ok', tournament: tournaments.get(actualId - 1)});
});

app.post('/setresult', (req, reply) => {
	try {
		postResult(req.body.result.id, req.body.result);
	}
	catch (err)
	{
		console.log(err);
		reply.send({ status: 'error', err: err});
		return;
	}
	reply.send({ status: 'ok' });
});

app.post('/gettournament', (req, reply) => {
	const { id } = req.body;
	reply.send({ tournament: tournaments.get(parseInt(id))});
});

app.delete('/deletetournament', (req, reply) => {
	const { id } = req.body;
	console.log('Deleting tournament with id: ' + id);
	tournaments.delete(id);
});

// Shutdown
const gracefulShutdown = async () => {
	try {
	  await app.close();
	  console.log('Server shut down successfully');
	  process.exit(0);
	} catch (err) {
	  console.error('Server shutdown failure');
	  process.exit(1);
	}
  };
  
  // Start
  const start = async () => {
	try {
	  await app.ready();
	  await app.listen({ port: PORT, host: "0.0.0.0" });
	  console.log('Server ready');
  
	  process.on("SIGINT", gracefulShutdown);
	  process.on("SIGTERM", gracefulShutdown);
	} catch (err) {
	  console.error('Server failed: ' + err);
	  process.exit(1);
	}
  };
  
  start();
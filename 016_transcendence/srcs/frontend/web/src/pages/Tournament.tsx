import React, { useState, useEffect } from "react";
import { useLocation, useSearchParams } from "react-router-dom";
import TournamentBracket from "../components/TournamentBracket";

interface Tournament {
  id: number;
  nextmatch: {
    round: string;
    side: string;
    match: string;
    p1: string;
    p2: string;
  } | undefined;
  [key: string]: any;
}

let tournamentId: number | undefined;
let tournamentData: Tournament | undefined;

const Tournament: React.FC = () => {
  const location = useLocation();
  
  const [numPlayers, setNumPlayers] = useState<number | null>(null);
  const [playerNames, setPlayerNames] = useState<string[]>([]);
  const [showSetup, setShowSetup] = useState<boolean>(true);
  const [isGameCompleted, setIsGameCompleted] = useState<boolean>(false);
  const [searchParams] = useSearchParams();
  const [forceUpdate, setForceUpdate] = useState<number>(0);

  useEffect(() => {
    const params = new URLSearchParams(location.search);
    const fromGame = params.get("fromGame");
    const winner = params.get("winner");
    const tournId = params.get("tournamentId");
    const roundParam = params.get("round");
    const sideParam = params.get("side");
    const matchParam = params.get("match");
    
    if (fromGame === "true" && winner && tournId) {
      const tournamentIdNum = parseInt(tournId);
      tournamentId = tournamentIdNum;
      setShowSetup(false);
      submitMatchResult(winner, tournamentIdNum, roundParam || "", sideParam || "", matchParam || "");
    }
  }, [location]);

  useEffect(() => {
    const sideParam = searchParams.get("id");
    if (sideParam) {
      const SideParam = searchParams.get("id");
      tournamentId = parseInt(SideParam || "0");
      setShowSetup(false);
      fetchTournamentData();
    }
  }, [showSetup]);

  const handleNumPlayersClick = (num: number) => {
    setNumPlayers(num);
    setPlayerNames(Array(num).fill(""));
  };

  const handleNameChange = (index: number, name: string) => {
    const updatedNames = [...playerNames];
    updatedNames[index] = name;
    setPlayerNames(updatedNames);
  };

  const handleSubmit = async () => {
    if (!numPlayers || playerNames.some((name) => name.trim() === ""))
    {
      alert("Error, completa todos los nombres correctamente.");
      return;
    }

    const uniqueNames = new Set(playerNames);
    if (uniqueNames.size !== playerNames.length)
    {
      alert("Error, no puede haber nombres repetidos.");
      return;
    }

    try {
      let players: { [key: string]: string | undefined } = {
        p1: undefined, p2: undefined, p3: undefined, p4: undefined,
        p5: undefined, p6: undefined, p7: undefined, p8: undefined,
        p9: undefined, p10: undefined, p11: undefined, p12: undefined,
        p13: undefined, p14: undefined, p15: undefined, p16: undefined
      };
      
      for (let i = 0; i < numPlayers; i++) {
        players[`p${i + 1}`] = playerNames[i];
      }

      const response = await fetch(`https://${window.location.host}/api/tournament/create`, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          numofplayers: numPlayers,
          players: players,
        }),
      });
      
      const data = await response.json();
      
      if (data.status === "ok" && data.tournament) {
        tournamentData = data.tournament;
        tournamentId = data.tournament.id;
        setShowSetup(false);
      } else {
        alert("Error al crear el torneo: " + (data.error || "Error desconocido"));
      }
    } catch (error) {
      console.error(error);
      alert("Error al crear el torneo!");
    }
  };

  const submitMatchResult = async (winner: string, tournId: number, round: string, side: string, match: string) => {
    try {
      const response = await fetch("/api/tournament/setresult", {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({
          id: tournId,
          result: {
            side: side,
            round: round,
            match: match,
            winner: winner
          }
        }),
      });
      
      const data = await response.json();
      
      fetchTournamentData();
    }
    catch (error) {
      console.error("Error en submitMatchResult:", error);
      alert("Error al enviar el resultado!");
    }
  };

  const fetchTournamentData = async () => {

    if (tournamentId === undefined) {
      tournamentId = parseInt(searchParams.get("id") || "");
      if (!tournamentId) {
        console.error("ID de torneo no válido");
        return;
      }
    }
    try {
      const response = await fetch(`https://${window.location.host}/api/tournament/gettournament`, {
        method: "POST",
        headers: {
          "Content-Type": "application/json",
        },
        body: JSON.stringify({ id: tournamentId }),
      });
      
      const data = await response.json();
      
      if (data && data.tournament) {
        tournamentData = data.tournament;
        
        const isCompleted = tournamentData?.nextmatch === null;
        setIsGameCompleted(isCompleted);

        setForceUpdate(prev => prev + 1);
      }
    } catch (error) {
      console.error(error);
    }
  };

  const startMatch = () => {
    if (!tournamentData || !tournamentData.nextmatch) return;
        
    const { p1, p2, round, side, match } = tournamentData.nextmatch;
    
    // Redirigir a Game.tsx con los parámetros necesarios
    window.location.href = `/game?players=6&tournamentMode=true&tournamentId=${tournamentId}&p1=${p1}&p2=${p2}&round=${round}&side=${side}&match=${match}`;
  };

  ///////////////////////////////////////////////////
  // Renderizar el partido actual o resultado final
  //////////////////////////////////////////////////

  const renderCurrentMatch = () => {
    if (!tournamentData) {
      return null;
    }
    
    const lastRound = Object.keys(tournamentData)
      .filter(key => key.startsWith('round'))
      .sort((a, b) => parseInt(b.substring(5)) - parseInt(a.substring(5)))[0];
      
    if (lastRound && tournamentData[lastRound].final?.winner) {
      return (
        <div className="text-center p-8 bg-gray-800 rounded-lg shadow-lg mt-4">
          <h2 className="text-3xl font-bold text-green-400 mb-4">¡Torneo Finalizado!</h2>
          <div className="text-2xl mb-6">
            Ganador: <span className="font-bold text-yellow-300">{tournamentData[lastRound].final.winner}</span>
          </div>
          <button
            onClick={() => window.location.href = "/"}
            className="px-6 py-3 bg-blue-600/50 hover:bg-blue-700/50 rounded-lg text-xl font-bold"
          >
            Volver al menú principal
          </button>
        </div>
      );
    }

    if (!tournamentData.nextmatch) {
      return (
        <div className="text-center">
          <p className="text-xl">No hay partidos disponibles en este momento.</p>
        </div>
      );
    }
   
    return null;
  };

  return (
    <div className="flex flex-col items-center justify-center min-h-screen text-white p-4">
      {showSetup ? (
        <>
          <h1 className="text-3xl font-bold mb-8">¿Cuantos jugadores participaran?</h1>
          
          <div className="flex gap-4 mb-6">
            <button
              onClick={() => handleNumPlayersClick(4)}
              className="text-2xl px-4 py-2 bg-pink-600/50 hover:bg-pink-700/50 rounded-full"
            >
              4
            </button>
            <button
              onClick={() => handleNumPlayersClick(8)}
              className="text-2xl px-4 py-2 bg-pink-600/50 hover:bg-pink-700/50 rounded-full"
            >
              8
            </button>
            <button
              onClick={() => handleNumPlayersClick(16)}
              className="text-2xl px-4 py-2 bg-pink-600/50 hover:bg-pink-700/50 rounded-full"
            >
              16
            </button>
          </div>

          {numPlayers && (
            <div className="w-full max-w-md">
              <h2 className="text-xl text-center font-semibold mb-8">
                Introduce sus {numPlayers} nombres:
              </h2>
              {playerNames.map((name, index) => (
                <div key={index} className="mb-2">
                  <input
                    type="text"
                    value={name}
                    onChange={(e) => handleNameChange(index, e.target.value)}
                    placeholder={`Jugador ${index + 1}`}
                    className="text-center w-full px-4 py-2 rounded-lg bg-gray-800 text-white border border-gray-700 focus:outline-none focus:ring-2 focus:ring-blue-500"
                  />
                </div>
              ))}

              <button
                onClick={handleSubmit}
                className="mt-8 w-full px-4 py-2 bg-green-600/50 hover:bg-green-700/50 rounded-lg"
              >
                ¡Comienzo de torneo!
              </button>
            </div>
          )}
        </>
      ) : (
        <div className="flex flex-col items-center w-full max-w-6xl">
          <div className="w-full mb-8 overflow-auto bg-gray-900/50 rounded-lg p-4">
            <h2 className="text-2xl font-bold text-center mb-6">Cuadro del Torneo</h2>
            <TournamentBracket tournamentData={tournamentData} key={forceUpdate} />
          </div>
          
          {renderCurrentMatch()}
          
          {!isGameCompleted && tournamentData?.nextmatch && (
            <div className="bg-gray-800 p-6 rounded-lg shadow-lg w-full max-w-md mt-8">
            <h2 className="text-2xl font-bold text-center mb-6">Partido Actual</h2>
            
            <div className="flex justify-between items-center mb-8">
              <div className="text-center w-1/3">
                <div className="text-xl font-bold mb-2">{tournamentData.nextmatch.p1}</div>
              </div>
              
              <div className="text-2xl font-bold">VS</div>
              
              <div className="text-center w-1/3">
                <div className="text-xl font-bold mb-2">{tournamentData.nextmatch.p2}</div>
              </div>
            </div>
            
            <div className="flex justify-center mt-4">
              <button
                onClick={startMatch}
                className="px-6 py-3 bg-pink-600/50 hover:bg-pink-700/50 rounded-lg text-xl font-bold"
              >
                Iniciar Partido
              </button>
            </div>
          </div>
          )}
        </div>
      )}
    </div>
  );
};

export default Tournament;
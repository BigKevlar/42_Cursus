import { useEffect, useState, useRef } from "react";
import redirectIfNotLoggedIn from "../components/utils/RedirectIfNotLogged";

const Sprinter = () => {
  redirectIfNotLoggedIn();

  const [gameState, setGameState] = useState<any>(null);
  const [winner, setWinner] = useState<string | null>(null);
  const [lock, setLock] = useState(false);
  const socketRef = useRef<WebSocket | null>(null);

  useEffect(() => {
    const socket = new WebSocket(`wss://${window.location.host}/api/sprinter`);
    socketRef.current = socket;

    socket.onopen = () => {
      console.log("🔗 WebSocket conectado");
    };

    socket.onmessage = (event) => {
      const data = JSON.parse(event.data);
      setGameState(data);

      if (data.winner) {
        if (data.winner === "player1") {
          setWinner("anti-" + localStorage.getItem("username"));
        } else
        setWinner(localStorage.getItem("username"));
      }
    };

    socket.onerror = (error) => {
      console.error("❌ Error en WebSocket:", error);
    };

    socket.onclose = () => {
      console.log("🔌 WebSocket desconectado");
    };

    return () => {
      if (socket && socket.readyState === WebSocket.OPEN) {
        socket.close();
      }
    };
  }, []);

  const sendCommand = (command: string) => {
    if (socketRef.current && socketRef.current.readyState === WebSocket.OPEN) {
      setLock(true);
      socketRef.current.send(command);
    } else {
      console.error("❌ WebSocket no está conectado");
    }
  };

  // Manejar las teclas presionadas
  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
      switch (event.key) {
        case "a":
          sendCommand("p1-left");
          event.preventDefault();
          break;
        case "d":
          sendCommand("p1-right");
          event.preventDefault();
          break;
        case "ArrowLeft":
          sendCommand("p2-left");
          event.preventDefault();
          break;
        case "ArrowRight":
          sendCommand("p2-right");
          event.preventDefault();
          break;
        default:
          break;
      }
    };

    window.addEventListener("keydown", handleKeyDown);
    return () => window.removeEventListener("keydown", handleKeyDown);
  }, []);

  const handleReplay = () => {
    window.location.href = "/sprinter";
    console.log("🔄 Reiniciando el juego...");
  };

  const handleGoHome = () => {
    window.location.href = "/";
    console.log("🏠 Volviendo al menú principal...");
  };

  /*************************/
  /* RENDERIZADO DEL JUEGO */
  /*************************/

  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-transparent text-white">
      <div className="relative z-10 w-full max-w-6xl">
        <h1 className="text-3xl font-bold mb-4 text-center">MINIJUEGO SPRINTER</h1>
        
        {!lock && (
          <div className="flex justify-center space-x-4 mb-6">
            <button
              onClick={() => sendCommand("new solo-game")}
              className="bg-indigo-600 hover:bg-indigo-700 text-white font-bold py-2 px-4 rounded transition"
            >
              JUGAR
            </button>
          </div>
        )}

        {/* Área del juego */}
        <div className="relative mx-auto mt-6 bg-brown-800 border-2 border-black overflow-hidden"
          style={{
            height: "400px",
            width: "90%",
            backgroundColor: "rgba(139, 69, 19, 0.7)",
          }}>
          
          {/* Pistas */}
          {[1, 2].map((lane) => (
            <div
              key={lane}
              className="absolute w-full"
              style={{
                height: "50%",
                backgroundColor: lane === 1 ? "rgba(255, 255, 255, 0.1)" : "rgba(0, 0, 0, 0.1)",
                borderTop: lane === 1 ? "2px dashed white" : "none",
                borderBottom: "2px dashed white",
                top: `${(lane - 1) * 50}%`,
              }}
            ></div>
          ))}

          {/* Líneas de inicio/meta */}
          <div className="absolute top-0 left-0 w-2 h-full bg-yellow-500"></div>
          <div className="absolute top-0 right-0 w-2 h-full bg-green-500"></div>

          {/* Jugadores */}
          {gameState?.player1 && (
            <div
              className="absolute bottom-60 left-0 w-24 h-20 bg-contain bg-no-repeat"
              style={{
                left: `${(gameState.player1.distance || 0) * 10}px`,
                backgroundImage: "url('/sprinter/sprinter1.png')",
              }}
            ></div>
          )}

          {gameState?.player2 && (
            <div
              className="absolute bottom-20 left-0 w-24 h-20 bg-contain bg-no-repeat"
              style={{
                left: `${(gameState.player2.distance || 0) * 10}px`,
                backgroundImage: "url('/sprinter/sprinter2.png')",
              }}
            ></div>
          )}

          {/* Pantalla de fin de juego */}
          {winner && (
            <div className="absolute inset-0 bg-black bg-opacity-80 flex flex-col items-center justify-center">
              <h2 className="text-4xl font-bold mb-6 text-white">¡{winner} HA GANADO!</h2>
              <div className="flex space-x-4">
                <button
                  onClick={handleReplay}
                  className="bg-indigo-600 hover:bg-indigo-700 text-white font-bold py-2 px-6 rounded transition"
                >
                  Jugar de nuevo
                </button>
                <button
                  onClick={handleGoHome}
                  className="bg-gray-600 hover:bg-gray-700 text-white font-bold py-2 px-6 rounded transition"
                >
                  Menú principal
                </button>
              </div>
            </div>
          )}
        </div>
      </div>
    </div>
  );
};

export default Sprinter;
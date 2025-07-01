import { useEffect, useState, useRef } from "react";                      // Usamos esta funcionalidad de libreria para manejo de estados y efectos en componentes funcionales.
import { useSearchParams } from "react-router-dom";                       // Y esta para para leer y manejar parametros de URL.
import redirectIfNotLoggedIn from "../components/utils/RedirectIfNotLogged";

const Game = () => {

  redirectIfNotLoggedIn();
  const username = localStorage.getItem("username") || "Jugador 1";       // Obtenemos el nombre del jugador desde el localStorage.
  const [searchParams] = useSearchParams();

  const [ball, setBall] = useState({ x: 400, y: 300 });
  const [ball1, setBall1] = useState({ x: 400, y: 300 });
  const [ball2, setBall2] = useState({ x: 400, y: 300 });
  const [player1, setPlayer1] = useState(300);
  const [player2, setPlayer2] = useState(300);
  const [player3, setPlayer3] = useState(300);
  const [player4, setPlayer4] = useState(300);
  const [player1Len, setPlayer1Len] = useState(100);
  const [player2Len, setPlayer2Len] = useState(100);
  const [player3Len, setPlayer3Len] = useState(100);
  const [player4Len, setPlayer4Len] = useState(100);
  const [player1Score, setPlayer1Score] = useState(0);
  const [player2Score, setPlayer2Score] = useState(0);
  const [player3Score, setPlayer3Score] = useState(0);
  const [player4Score, setPlayer4Score] = useState(0);
  const [winner, setWinner] = useState<string | null>(null);                // Evento de estado para el ganador.
  const [keysPressed, setKeysPressed] = useState<Set<string>>(new Set());   // Evento de estado para controlar las teclas presionadas.

  const [counter, setCounter] = useState<number | null>(null);              // Estado para la cuenta atrás.
  const [waiting, setWaiting] = useState(true);                             // Estado para esperar a los jugadores.

  const players = searchParams.get("players") || "1";                       // Variable para guardar el numero de jugadores para el boton del menu.
  const SCORE_MAX = 5;                                                      // Limite maximo de puntuación para ganar.
  const SCORE_MIN = 0;                                                      // Limite minimo de puntuación para ganar.

  const socketRef = useRef<WebSocket | null>(null);                         // Variable para guardar el websocket.

  const [playerNames, setPlayerNames] = useState({                          // En esta variable guardamos los nombres de los jugadores, por defecto ninguno salvo el primero.
    player1: "",
    player2: "",
    player3: "",
    player4: "",
  });

  const TournamentId = searchParams.get("tournamentId");
  const Side = searchParams.get("side");                  
  const Round = searchParams.get("round");                  
  const Match = searchParams.get("match");                   


  //////////////////////////////////////////////////////////////////////
  // FUNCION PARA CONEXION DEL WEBSOCKET Y RECEPCION DE DATOS DE BACK //
  //////////////////////////////////////////////////////////////////////

  useEffect(() => {

      if (socketRef.current) {
        console.log("⚠️ WebSocket ya está inicializado.");
        return; // Evita abrir una nueva conexión si ya existe una.
      }
	  
	  // Con esto el websocket va a traves de nginx -> gateway -> game por wss
	  const socket = new WebSocket(`wss://${window.location.host}/api/game`);    
    socketRef.current = socket;

    socket.onopen = () => {
      switch (players) {

        case "1": // 1 VS IA
          console.log("🔗 Conexión WebSocket establecida para 1 VS IA.");
          setCounter(3);
          break;
    
        case "2": // PVP
          console.log("🔗 Conexión WebSocket establecida para PVP.");
          setCounter(3);
          break;
    
        case "3": // BATTLE ROYALE
          console.log("🔗 Conexión WebSocket establecida para BATTLE ROYALE.");
          setCounter(3);
          break;
    
        case "4": // REMOTE GAME
          console.log("🔗 Conexión WebSocket establecida para REMOTE GAME.");
          socket.send(JSON.stringify({ mode: 'new remote-game', name: username }));
          setWaiting(true); // Espera a que se unan jugadores.
          setCounter(null); // No inicia la cuenta atrás directamente.
          break;
    
        case "5": // BATLE ROYALE REMOTE
          console.log("🔗 Conexión WebSocket establecida para BATLE ROYALE REMOTE.");
          socket.send(JSON.stringify({ mode: 'new multiplayer-game (remote)', name: username }));
          setWaiting(true); // Espera a que se unan jugadores.
          setCounter(null); // No inicia la cuenta atrás directamente.
          break;

        case "6": // TOURNAMENT
          console.log("🔗 Conexión WebSocket establecida para TOURNAMENT.");
          setCounter(3);
          break;

        default:
          console.error("❌ Modo de juego no válido:", players);
          break;
          
      }
    };

    // Recibimos el feedback del backend y recibimos los datos del juego.
    socket.onmessage = (event) => {

      const data = JSON.parse(event.data);
      // Si el juego es remoto, se espera el mensaje "ready" del backend para iniciar la cuenta atrás.
      if (players === "4" || players === "5") {
        // Si el backend envía "ready", sincronizamos la cuenta atrás.
        if (data === "ready") {
          setWaiting(false); // Finaliza la pantalla de espera.
          setCounter(3); // Inicia la cuenta atrás sincronizada.
          //socket.send("ready"); // Confirmamos al backend que estamos listos.
          return ;
        }
      }

      // Ponemos los nombres de los jugadores en la pantalla según el modo de juego.
      if (players === "1")
      {
        setPlayerNames({
          player1: username,
          player2: "AI",
          player3: "",
          player4: "",
        });
      }
      else if (players === "2")
      {
        setPlayerNames({
          player1: username,
          player2: "anti-" + username,
          player3: "",
          player4: "",
        });
      }
      else if (players === "3")
      {
        setPlayerNames({
          player1: username,
          player2: "anti-" + username + "_v.2",
          player3: "anti-" + username + "_v.3",
          player4: "anti-" + username + "_v.4",
        });
      }
      else if (players === "4")
      {
        setPlayerNames({
          player1: data.playersNames.right,
          player2: data.playersNames.left,
          player3: "",
          player4: "",
        });
      }
      else if (players === "5")
      {
        console.log("📩 Nombres recibidos:", data.playersNames);
        setPlayerNames({
          player1: data.playersNames.right,
          player2: data.playersNames.left,
          player3: data.playersNames.up,
          player4: data.playersNames.down || "Jugador 4", // Valor predeterminado si está vacío
        });
      }
      else if (players === "6")
      {
        setPlayerNames({
          player1: searchParams.get("p1") || "",
          player2: searchParams.get("p2") || "",
          player3: "",
          player4: ""
        });
      }

      // Actualizamos el estado del juego con los datos recibidos del backend.
      setBall(data.ball);
      setBall1(data.ball1);
      setBall2(data.ball2);
      setPlayer1(data.paddles.left);
      setPlayer2(data.paddles.right);
      setPlayer3(data.paddles.up);
      setPlayer4(data.paddles.down);
      setPlayer1Len(data.paddlesLen.left);
      setPlayer2Len(data.paddlesLen.right);
      setPlayer3Len(data.paddlesLen.up);
      setPlayer4Len(data.paddlesLen.down);
      setPlayer1Score(Math.max(0, data.score.left));
      setPlayer2Score(Math.max(0, data.score.right));
      setPlayer3Score(Math.max(0, data.score.up));
      setPlayer4Score(Math.max(0, data.score.down));
    };

    // En caso de error en la conexión imprimimos log.
    socket.onerror = (error) => {
      console.error("❌ Fallo en la conexion con el WebSocket!!!", error);
    };

    // Limpiamos conexión al desmontar el componente para evitar fugas de memoria (pura seguridad porsi porsi).
    return () => {
      if (socket && socket.readyState === WebSocket.OPEN) {
        socket.close();
        console.log("🔌 Conexión WebSocket cerrada correctamente.");
      }
    };

  }, [players]);

  ////////////////////////////////////////
  // FUNCION PARA MANEJAR LOS GANADORES //
  ////////////////////////////////////////

  useEffect(() => {
    // Verifica si hay un ganador en los modos 1, 2 o 4.
    if (players === "1" || players === "2" || players === "4" || players === "6")
    {
      if (player1Score >= SCORE_MAX)
      {
        console.log(`${playerNames.player1} ha ganado`);
        setWinner(playerNames.player1);
      }
      else if (player2Score >= SCORE_MAX)
      {
        console.log(`${playerNames.player2} ha ganado`);
        setWinner(playerNames.player2);
      }
    }
  
    // Verifica si hay un ganador en los modos 3 o 5.
    if (players === "3" || players === "5")
    {
      const scores = [
        { player: playerNames.player1, score: player1Score },
        { player: playerNames.player2, score: player2Score },
        { player: playerNames.player3, score: player3Score },
        { player: playerNames.player4, score: player4Score },
      ];
  
      // Filtra los jugadores que aún tienen un puntaje positivo.
      const remainingPlayers = scores.filter((player) => player.score > SCORE_MIN);
  
      if (remainingPlayers.length === 1)
      {
        console.log(`${remainingPlayers[0].player} ha ganado`);
        setWinner(remainingPlayers[0].player);
      }
    }
  }, [player1Score, player2Score, player3Score, player4Score, playerNames,players]);

  ////////////////////////////////////////////////////
  // FUNCION PARA INICIAR LA CUENTA ATRAS DEL JUEGO //
  ////////////////////////////////////////////////////

  useEffect(() => {

    if (counter !== null && counter > 0)
    {
      const timer = setTimeout(() => setCounter(counter - 1), 1000);
      return () => clearTimeout(timer);
    }
    else if (counter === 0)
    {
      console.log("⏰ Cuenta atrás finalizada, iniciando juego...");
      setWaiting(false); // Finaliza la espera y comienza el juego.

      const socket = socketRef.current;
      if (socket && socket.readyState === WebSocket.OPEN)
      {
        if (players === "1")
          socket.send(JSON.stringify({ mode: 'new AI-game'}));
        else if (players === "2")
          socket.send(JSON.stringify({ mode: 'new solo-game'}));
        else if (players === "3")
          socket.send(JSON.stringify({ mode: 'new multiplayer-game (local)'}));
        else if (players === "6")
          socket.send(JSON.stringify({ mode: 'new tournament-game', datamatch: { id: TournamentId, side: Side, round: Round, match: Match } }));
      }
    }
  }, [counter]);

  //////////////////////////////////////////////////////////////
  // FUNCION PARA MANEJAR TECLAS PRESIONADAS Y DESPRESIONADAS //
  //////////////////////////////////////////////////////////////

  useEffect(() => {

    const handleKeyDown = (event: KeyboardEvent) => {
      if (event.key === "ArrowUp" || event.key === "ArrowDown")
        event.preventDefault(); // Evitamos el scroll de la pagina.
      setKeysPressed((prev) => new Set(prev).add(event.key)); // Aqui agregamos la tecla al estado.
    };

    const handleKeyUp = (event: KeyboardEvent) => {
      setKeysPressed((prev) => {
        const newKeys = new Set(prev);
        newKeys.delete(event.key); // Aqui eliminamos la tecla del estado.
        return newKeys;
      });
    };

    // Actualizamos el estado de las teclas presionadas.
    window.addEventListener("keydown", handleKeyDown);
    window.addEventListener("keyup", handleKeyUp);

    // Limpiamos los eventos al desmontar el componente, en este caso el de las teclas.
    return () => {
      window.removeEventListener("keydown", handleKeyDown);
      window.removeEventListener("keyup", handleKeyUp);
    };

  }, []);

  ///////////////////////////////////////////////////////////////////////////
  // FUNCION PARA ENVIAR COMANDOS AL BACK EN FUNCIÓN DE TECLAS PRESIONADAS //
  ///////////////////////////////////////////////////////////////////////////

  useEffect(() => {

    const updateMovement = () => {
      const socket = socketRef.current; // Usamos el websocket de referencia que teniamos guardado.
      if (!socket || socket.readyState !== WebSocket.OPEN) return; // Verificamos si el websocket esta abierto, y enviamos el mensaje de tecla.
      // Estas son las teclas habilitadas para cada modo de juego.
      if (players === "1")
      {
        if (keysPressed.has("ArrowUp")) {
          socket.send("l-up");
        }
        if (keysPressed.has("ArrowDown")) {
          socket.send("l-down");
        }
      }
      else if (players === "2" || players === "6")
      {
        if (keysPressed.has("w")) {
          socket.send("l-up");
        }
        if (keysPressed.has("s")) {
          socket.send("l-down");
        }
        if (keysPressed.has("ArrowUp")) {
          socket.send("r-up");
        }
        if (keysPressed.has("ArrowDown")) {
          socket.send("r-down");
        }
      }
      else if (players === "3")
      {
        if (keysPressed.has("w")) {
          socket.send("l-up");
        }
        if (keysPressed.has("s")) {
          socket.send("l-down");
        }
        if (keysPressed.has("ArrowUp")) {
          socket.send("r-up");
        }
        if (keysPressed.has("ArrowDown")) {
          socket.send("r-down");
        }
        if (keysPressed.has("c")) {
          socket.send("u-left");
        }
        if (keysPressed.has("v")) {
          socket.send("u-right");
        }
        if (keysPressed.has("n")) {
          socket.send("d-left");
        }
        if (keysPressed.has("m")) {
          socket.send("d-right");
        }
      }
      else if (players === "4")
      {
        if (keysPressed.has("ArrowUp")) {
          socket.send("up");
        }
        if (keysPressed.has("ArrowDown")) {
          socket.send("down");
        }
      }
      else if (players === "5")
        {
          if (keysPressed.has("ArrowUp")) {
            socket.send("up");
          }
          if (keysPressed.has("ArrowDown")) {
            socket.send("down");
          }
          if (keysPressed.has("ArrowLeft")) {
            socket.send("left");
          }
          if (keysPressed.has("ArrowRight")) {
            socket.send("right");
          }
        }
    };

    // Actualizamos el movimiento cada 16ms (= 60fps mas o menos).
    const interval = setInterval(updateMovement, 16);

    // Limpiamos intervalo.
    return () => clearInterval(interval);
  }, [keysPressed, players]); // Dejamos en escucha de cambios las teclas presionadas.

  ////////////////////////////////////////////////////////
  // FUNCION DE REINICIAR JUEGO TRAS FINALIZAR EL JUEGO //
  ////////////////////////////////////////////////////////

  const handleReplay = () => {
    if (players === "1")
      window.location.href = "/game?players=1"; // Redirige al juego de 1 vs IA
    else if (players === "2")
      window.location.href = "/game?players=2"; // Redirige al juego de PVP
    else if (players === "3")
      window.location.href = "/game?players=3"; // Redirige al juego de BATTLE ROYALE
    else if (players === "4")
      window.location.href = "/game?players=4"; // Redirige al juego de REMOTE GAME
    else if (players === "5")
      window.location.href = "/game?players=5"; // Redirige al juego de BATLE ROYALE REMOTE
    console.log("🔄 Reiniciando el juego...");
  };

  ///////////////////////////////////////////////////////
  // FUNCION DE VOLVER AL HOME TRAS FINALIZAR EL JUEGO //
  ///////////////////////////////////////////////////////

  const handleGoHome = () => {
    window.location.href = "/"; // Redirige al menú principal
    console.log("🏠 Volviendo al menú principal...");
  };

  ////////////////////////////////////
  // FUNCION DE CONTINUAR EL TORNEO //
  ////////////////////////////////////

  const handleContinue = () => {
    window.location.href = `/tournament?id=${TournamentId}`; // Redirige al menú principal
  };

  ////////////////////////////////////////////////////////////////////////
  // FRONTEND DE RENDERIZACION DE LA PANTALLA DE CONTADOR Y/O DEL JUEGO //
  ////////////////////////////////////////////////////////////////////////

  // Mostrar pantalla de espera si estamos esperando jugadores (modos remotos).
  if (waiting && (players === "4" || players === "5"))
  {
    return (
      <div className="flex items-center justify-center h-screen bg-gradient-to-br">
        <p className="text-white text-4xl font-bold">Esperando jugadores...</p>
      </div>
    );
  }
  // Si no, mostramos la cuenta atrás si está activa.
  else if (counter !== null && counter > 0)
  {
    return (
      <div className="flex items-center justify-center h-screen bg-gradient-to-br">
        <p className="text-white text-6xl font-bold">
          {counter}
        </p>
      </div>
    );
  }
  // Y si tampoco, renderizamos el juego si el contador aún no ha comenzado.
  else if (counter === null)
  {
    return null;
  }
  else if (players === "1" || players === "2" || players === "4")
  {
    return (
      <div className="relative mx-auto mt-10 h-[610px] w-[800px] bg-black border-2 border-white overflow-hidden">
        
        {/* Nombre del jugador 1 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            writingMode: "vertical-rl",
            top: "50%",
            left: "0.1%",
            transform: "translateY(-50%) rotate(180deg)",
          }}
        >
          {playerNames.player1}
        </div>
        
        {/* Puntuación del jugador 1 */}
        <div
          className="absolute text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
            top: "50%", // Centrado verticalmente
            left: "40%", // Frente a la línea vertical izquierda
            transform: "translate(-50%, -50%)", // Centrado
          }}
        >
          {player1Score}
        </div>

        {/* Nombre del jugador 2 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            writingMode: "vertical-rl",
            top: "50%",
            right: "0.1%",
            transform: "translateY(-50%)",
          }}
        >
          {playerNames.player2}
        </div>

        {/* Puntuación del jugador 2 */}
        <div
          className="absolute text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
            top: "50%", // Centrado verticalmente
            right: "40%", // Frente a la línea vertical derecha
            transform: "translate(50%, -50%)", // Centrado
          }}
        >
          {player2Score}
        </div>

        {/* Raqueta izquierda */}
        <div className="absolute left-1/2 transform -translate-x-1/2 h-full w-[4px] bg-transparent">
          <div className="h-full w-full bg-[repeating-linear-gradient(white_0_10px,transparent_10px_20px)]"></div>
        </div>
        <div
          className="absolute w-[10px] h-[100px] bg-white"
          style={{ top: `${player1 - 50}px`, left: `40px` }}
        ></div>

        {/* Raqueta derecha */}
        <div
          className="absolute w-[10px] h-[100px] bg-white"
          style={{ top: `${player2 - 50}px`, left: `750px` }}
        ></div>

        {/* Bola */}
        <div
          className="absolute w-[20px] h-[20px] bg-white"
          style={{
            top: `${Math.max(0, Math.min(590, ball.y - 10))}px`,
            left: `${ball.x - 10}px`,
          }}
        ></div>

        {/* Mensaje del ganador y botones de home o reinicio */}
        {winner && (
          <div className="absolute inset-0 bg-black bg-opacity-75 flex items-center justify-center z-50">
            <div className="text-white text-4xl font-bold text-center">
              ¡{winner} HA GANADO!
              <br />
              <div className="flex space-x-4 mt-4">
                <button
                  onClick={handleReplay}
                  className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded"
                >
                  Volver a jugar
                </button>
                <button
                  onClick={handleGoHome}
                  className="bg-gray-500 hover:bg-gray-700 text-white font-bold py-2 px-4 rounded"
                >
                  Volver al menú
                </button>
              </div>
            </div>
          </div>
        )}
      </div>
    );
  }
  else if (players === "3" || players === "5")
  {
    return (
      <div
        className="relative mx-auto mt-10 h-[800px] w-[800px] bg-black border-2 border-white overflow-hidden"
        style={{
          clipPath:
            "polygon(0% 0%, 0% 12.5%, 12.5% 12.5%, 12.5% 0%, 87.5% 0%, 87.5% 12.5%, 100% 12.5%, 100% 0%, 100% 87.5%, 87.5% 87.5%, 87.5% 100%, 12.5% 100%, 12.5% 87.5%, 0% 87.5%, 0% 100%)",
        }}>

        {/* Nombre del jugador 1 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            writingMode: "vertical-rl",
            top: "50%",
            left: "0.1%",
            transform: "translateY(-50%) rotate(180deg)",
          }}
        >
          {playerNames.player1}
        </div>

        {/* Puntuacion del jugador 1 (izquierda) */}
        <div
          className="absolute left-1/4 top-1/2 transform -translate-x-1/2 -translate-y-1/2 text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
          }}
        >
          {player1Score}
        </div>

        {/* Nombre del jugador 2 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            writingMode: "vertical-rl",
            top: "50%",
            right: "0.1%",
            transform: "translateY(-50%)",
          }}
        >
          {playerNames.player2}
        </div>

        {/* Puntuacion del jugador 2 (derecha) */}
        <div
          className="absolute right-1/4 top-1/2 transform translate-x-1/2 -translate-y-1/2 text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
          }}
        >
          {player2Score}
        </div>

        {/* Nombre del jugador 3 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            top: "2%",
            right: "50%",
            transform: "translateY(-50%) translateX(50%)",
          }}
        >
          {playerNames.player3}
        </div>

        {/* Puntuacion del jugador 3 (arriba) */}
        <div
          className="absolute top-1/4 left-1/2 transform -translate-x-1/2 -translate-y-1/2 text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
          }}
        >
          {player3Score}
        </div>

        {/* Nombre del jugador 4 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            bottom: "2%",
            right: "50%",
            transform: "translateY(50%) translateX(50%)",
          }}
        >
          {playerNames.player4}
        </div>

        {/* Puntuacion del jugador 4 (abajo) */}
        <div
          className="absolute bottom-1/4 left-1/2 transform -translate-x-1/2 translate-y-1/2 text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
          }}
        >
          {player4Score}
        </div>

        {/* Raqueta izquierda */}
        <div
          className="absolute w-[10px] bg-white"
          style={{
            height: `${player1Len}px`,
            top: `${player1 - player1Len / 2}px`,
            left: `${player1Len > 100 ? 90 : 40}px`,
          }}
        ></div>

        {/* Raqueta derecha */}
        <div
          className="absolute w-[10px] bg-white"
          style={{
            height: `${player2Len}px`,
            top: `${player2 - player2Len / 2}px`,
            right: `${player2Len > 100 ? 90 : 40}px`,
          }}
        ></div>

        {/* Raqueta superior */}
        <div
          className="absolute h-[10px] bg-white"
          style={{
            width: `${player3Len}px`,
            top: `${player3Len > 100 ? 90 : 40}px`,
            left: `${player3 - player3Len / 2}px`,
          }}
        ></div>

        {/* Raqueta inferior */}
        <div
          className="absolute h-[10px] bg-white"
          style={{
            width: `${player4Len}px`,
            bottom: `${player4Len > 100 ? 90 : 40}px`,
            left: `${player4 - player4Len / 2}px`,
          }}
        ></div>

        {/* Bola 1 */}
        <div
          className="absolute w-[20px] h-[20px] bg-white"
          style={{
            top: `${Math.max(0, Math.min(780, ball1.y - 10))}px`,
            left: `${Math.max(0, Math.min(780, ball1.x - 10))}px`,
          }}
        ></div>

        {/* Bola 2 */}
        <div
          className="absolute w-[20px] h-[20px] bg-white"
          style={{
            top: `${Math.max(0, Math.min(780, ball2.y - 10))}px`,
            left: `${Math.max(0, Math.min(780, ball2.x - 10))}px`,
          }}
        ></div>

        {/* Linea de izquierda a derecha */}
        <div className="absolute left-1/2 transform -translate-x-1/2 h-full w-[4px] bg-transparent">
          <div
            className="h-full w-full bg-[repeating-linear-gradient(white_0_10px,transparent_10px_20px)]"
            style={{
              transform: "rotate(45deg)",
            }}
          ></div>
        </div>

        {/* Linea de derecha a izquierda */}
        <div className="absolute left-1/2 transform -translate-x-1/2 h-full w-[4px] bg-transparent">
          <div
            className="h-full w-full bg-[repeating-linear-gradient(white_0_10px,transparent_10px_20px)]"
            style={{
              transform: "rotate(-45deg)",
            }}
          ></div>
        </div>

        {/* Esquina superior izquierda */}
        <div className="absolute top-0 left-0 w-[100px] h-[100px] bg-transparent">
          <div className="absolute right-0 top-0 h-full w-[4px] bg-white"></div> {/* Borde derecho */}
          <div className="absolute bottom-0 left-0 w-full h-[4px] bg-white"></div> {/* Borde inferior */}
        </div>

        {/* Esquina superior derecha */}
        <div className="absolute top-0 right-0 w-[100px] h-[100px] bg-transparent">
          <div className="absolute left-0 top-0 h-full w-[4px] bg-white"></div> {/* Borde izquierdo */}
          <div className="absolute bottom-0 right-0 w-full h-[4px] bg-white"></div> {/* Borde inferior */}
        </div>

        {/* Esquina inferior izquierda */}
        <div className="absolute bottom-0 left-0 w-[100px] h-[100px] bg-transparent">
          <div className="absolute right-0 bottom-0 h-full w-[4px] bg-white"></div> {/* Borde derecho */}
          <div className="absolute top-0 left-0 w-full h-[4px] bg-white"></div> {/* Borde superior */}
        </div>
        
        {/* Esquina inferior derecha */}
        <div className="absolute bottom-0 right-0 w-[100px] h-[100px] bg-transparent">
          <div className="absolute left-0 bottom-0 h-full w-[4px] bg-white"></div> {/* Borde izquierdo */}
          <div className="absolute top-0 right-0 w-full h-[4px] bg-white"></div> {/* Borde superior */}
        </div>

        {/* Mensaje del ganador y botones de home o reinicio */}
        {winner && (
          <div className="absolute inset-0 bg-black bg-opacity-75 flex items-center justify-center z-50">
            <div className="text-white text-4xl font-bold text-center">
              ¡{winner} HA GANADO!
              <br />
              <div className="flex space-x-4 mt-4">
                <button
                  onClick={handleReplay}
                  className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded"
                >
                  Volver a jugar
                </button>
                <button
                  onClick={handleGoHome}
                  className="bg-gray-500 hover:bg-gray-700 text-white font-bold py-2 px-4 rounded"
                >
                  Volver al menú
                </button>
              </div>
            </div>
          </div>
        )}
      </div>
    );
  } 
  else if (players === "6")
  {
    return (
      <div className="relative mx-auto mt-10 h-[610px] w-[800px] bg-black border-2 border-white overflow-hidden">
        
        {/* Nombre del jugador 1 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            writingMode: "vertical-rl",
            top: "50%",
            left: "0.1%",
            transform: "translateY(-50%) rotate(180deg)",
          }}
        >
          {playerNames.player1}
        </div>
        
        {/* Puntuación del jugador 1 */}
        <div
          className="absolute text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
            top: "50%", // Centrado verticalmente
            left: "40%", // Frente a la línea vertical izquierda
            transform: "translate(-50%, -50%)", // Centrado
          }}
        >
          {player1Score}
        </div>

        {/* Nombre del jugador 2 */}
        <div
          className="absolute text-white text-2xl font-bold"
          style={{
            fontFamily: "monospace",
            letterSpacing: "0.2em",
            writingMode: "vertical-rl",
            top: "50%",
            right: "0.1%",
            transform: "translateY(-50%)",
          }}
        >
          {playerNames.player2}
        </div>

        {/* Puntuación del jugador 2 */}
        <div
          className="absolute text-white text-6xl font-bold"
          style={{
            fontFamily: "monospace",
            top: "50%", // Centrado verticalmente
            right: "40%", // Frente a la línea vertical derecha
            transform: "translate(50%, -50%)", // Centrado
          }}
        >
          {player2Score}
        </div>

        {/* Raqueta izquierda */}
        <div className="absolute left-1/2 transform -translate-x-1/2 h-full w-[4px] bg-transparent">
          <div className="h-full w-full bg-[repeating-linear-gradient(white_0_10px,transparent_10px_20px)]"></div>
        </div>
        <div
          className="absolute w-[10px] h-[100px] bg-white"
          style={{ top: `${player1 - 50}px`, left: `40px` }}
        ></div>

        {/* Raqueta derecha */}
        <div
          className="absolute w-[10px] h-[100px] bg-white"
          style={{ top: `${player2 - 50}px`, left: `750px` }}
        ></div>

        {/* Bola */}
        <div
          className="absolute w-[20px] h-[20px] bg-white"
          style={{
            top: `${Math.max(0, Math.min(590, ball.y - 10))}px`,
            left: `${ball.x - 10}px`,
          }}
        ></div>

        {/* Mensaje del ganador y botones de home o reinicio, si es torneo */}
        {winner && (
          <div className="absolute inset-0 bg-black bg-opacity-75 flex items-center justify-center z-50">
            <div className="text-white text-4xl font-bold text-center">
              ¡{winner} HA GANADO!
              <br />
              <div className="flex space-x-4 mt-4">
                <button
                  onClick={handleContinue}
                  className="bg-blue-500 hover:bg-blue-700 text-white font-bold py-2 px-4 rounded"
                >
                  Continuamos el torneo
                </button>
              </div>
            </div>
          </div>
        )}
      </div>
    );
  }  
  else {
    console.log("Modo de juego: " + players);
    return (
      <div className="flex items-center justify-center h-screen">
        <p className="text-white text-2xl">Error: Modo de juego no válido</p>
      </div>
    );
  }
}

export default Game;
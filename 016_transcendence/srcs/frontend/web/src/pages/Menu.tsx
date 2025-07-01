import React from "react";
import redirectIfNotLoggedIn from "../components/utils/RedirectIfNotLogged";

const GameMenu: React.FC = () => {
  const logged = redirectIfNotLoggedIn();
  const handlePlayerSelection = (players: number) => {
    window.location.href = `/game?players=${players}`;
  };

  if (!logged) {
    return null;
  }

  return (
    <div className="relative min-h-screen text-white">


      {/* Contenido principal */}
      <div className="relative z-20 max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-24 flex items-center justify-center">
        <div className="w-full max-w-md bg-gray-800/80 rounded-xl border border-gray-700 p-8 backdrop-blur-sm">
          <h1 className="text-4xl font-bold mb-8 text-center">
            ¿Cómo quieres jugar?
          </h1>
          
          <div className="space-y-4">
            {[
              {
                players: 1,
                label: "1 VS IA",
                color: "bg-green-600/50 hover:bg-green-700/50"
              },
              {
                players: 2,
                label: "PVP",
                color: "bg-green-600/50 hover:bg-green-700/50"
              },
              {
                players: 3,
                label: "¡BATTLE ROYALE!",
                color: "bg-green-600/50 hover:bg-green-700/50"
              },
              {
                players: 4,
                label: "REMOTE PVP",
                color: "bg-yellow-600/50 hover:bg-yellow-700/50"
              },
              {
                players: 5,
                label: "¡¡¡REMOTE BATTLE ROYALE!!!",
                color: "bg-red-600/50 hover:bg-red-700/50"
              }
            ].map((gameMode, index) => (
              <button
                key={index}
                onClick={() => handlePlayerSelection(gameMode.players)}
                className={`${gameMode.color} w-full text-white px-6 py-4 rounded-lg transition duration-300 border border-white/10 text-lg font-medium`}
              >
                {gameMode.label}
              </button>
            ))}
          </div>

          <div className="mt-8 text-center text-gray-400">
            <p>Selecciona un modo de juego para comenzar</p>
          </div>
        </div>
      </div>
    </div>
  );
};

export default GameMenu;
import React from "react";
import PingPongGame from "../components/PingPongGame";

const games = [
  {
    icon: (
      <a className="block w-12 h-12 mx-auto mb-4 hover:opacity-80 transition duration-300">
        <img src="home/pong.png" alt="Icono del juego principal" className="w-12 h-12"/>
      </a>
    ),
    title: "Juego clásico Pong",
    description:
      "Juega al clásico Pong en nuestro servidor: solo contra AI, con amigos o en modo BattleRoyale.",
  },
  {
    icon: (
      <a className="block w-12 h-12 mx-auto mb-4 hover:opacity-80 transition duration-300">
        <img src="home/second_game.png" alt="Icono del juego secundario" className="w-12 h-12 mx-auto mb-4 text-blue-400"/>
      </a>
    ),
    title: "Sprinter",
    description:
      "Tendrás disponible un minijuego secundario sencillo, por si quieres probar algo diferente.",
  },
  {
    icon: (
      <a className="block w-12 h-12 mx-auto mb-4 hover:opacity-80 transition duration-300">
        <img src="home/status.png" alt="Icono del estado del servidor" className="w-12 h-12 mx-auto mb-4 text-blue-400"/>
      </a>
    ),
    title: "Estado del servidor",
    description:
      "Comprueba el estado del servidor.",
  },
  {
    icon: (
      <a className="block w-12 h-12 mx-auto mb-4 hover:opacity-80 transition duration-300">
        <img src="home/team.png" alt="Icono del equipo" className="w-12 h-12 mx-auto mb-4 text-blue-400"/>
      </a>
    ),
    title: "Conoce al equipo",
    description:
      "Te contamos quienes somos y a qué nos dedicamos.",
  },
]

const Home: React.FC = () => {
  return (
    <div className="relative min-h-screen text-white">

      {/* Contenido principal */}
      <div className="relative z-20 max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 pt-16 pb-24">
        {/* Mensaje de bienvenida */}
        <div className="grid md:grid-cols-2 gap-8 mb-20 items-center">
          {/* Texto */}
          <div className="text-center ">
            <h2 className="text-4xl md:text-5xl font-extrabold mb-6 leading-tight">
              Bienvenido a nuestro "ft_trascendence"
            </h2>
            <p className="text-xl text-white/80">
              Es un placer que puedas/podais probar nuestro juego y comprobar
              nuestras habilidades FullStack en equipo!!!
            </p>
          </div>
          
          {/* Pong Game */}
          <div className="mt-8 lg:mt-0">
            <div className="relative w-full h-64 sm:h-80 md:h-96 lg:h-[400px]">
              <PingPongGame className="w-full h-full" />
            </div>
          </div>
        </div>

        {/* Características - Centered below */}
        <div className="grid grid-cols-1 sm:grid-cols-4 lg:grid-cols-4 gap-4 max-w-5xl mx-auto">
          {games.map((feature, index) => (
            <div
              key={index}
              className="bg-blue-600/50 p-6 rounded-xl border border-white/10 text-center"
            >
              {feature.icon}
              <h3 className="text-xl font-bold mb-3">{feature.title}</h3>
              <p className="text-white/70">{feature.description}</p>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
};

export default Home;
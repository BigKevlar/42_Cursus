import React from "react";
import { Link } from "react-router-dom";

function TranscendenceLogo() {
  return (
    <Link to="/" className="flex items-center">
    <img
      src="layoutLogo.png"
      alt="Transcendence Logo"
      className="h-16 w-auto"
    />
  </Link>
  );
}

function LightLink({ to, children }: { to: string; children: React.ReactNode }) {
  return (
    <Link
      to={to}
      className="text-gray-300 hover:bg-gray-700 hover:text-white px-3 py-2 rounded-md text-sm font-medium"
    >
      {children}
    </Link>
  );
}

function StrongLink({ to, children }: { to: string; children: React.ReactNode }) {
  return (
    <Link
      to={to}
      className="bg-blue-600/50 text-white px-3 py-2 rounded-md text-sm font-medium hover:bg-blue-700 transition"
    >
      {children}
    </Link>
  );
}

function LayoutNoLoggedIn() {
  return (
    <header className="bg-gray-800 border-b border-gray-700">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-4">
        <div className="flex justify-between items-center">
          <TranscendenceLogo />
          <nav className="flex space-x-4">
          <LightLink to="/team">Conoce al equipo</LightLink>
            <LightLink to="/status">Estado del servidor</LightLink>
            <StrongLink to="/login">Iniciar Sesión</StrongLink>
            <StrongLink to="/signup">Registrarse</StrongLink>
          </nav>
        </div>
      </div>
    </header>
  );

}

function LayoutLoggedIn() {

  const handleLogout = () => {
    localStorage.removeItem("username");
    localStorage.removeItem("token");
    window.location.href = "/";
  };

  const username = localStorage.getItem("username");

  return (
    <header className="bg-gray-800 border-b border-gray-700">
      <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-4">
        <div className="flex justify-between items-center">
          <div className="flex items-center space-x-4">
            <TranscendenceLogo />
            <p className="text-xl font-extrabold">Bienvenido, {username}</p>
          </div>
          <nav className="flex space-x-4 items-center">
            <LightLink to="/menu">Jugar a Pong</LightLink>
            <LightLink to="/sprinter">Jugar a Sprinter</LightLink>
            <LightLink to="/doom">Jugar a Doom</LightLink>
            <LightLink to="/tournament">Torneo</LightLink>
            <LightLink to="/status">Estado del servidor</LightLink>
            <LightLink to="/team">Conoce al equipo</LightLink>
            <button
              onClick={handleLogout}
              className="text-gray-300 hover:bg-gray-700 hover:text-white px-3 py-2 rounded-md text-sm font-medium transition-colors"
            >
              Cerrar Sesión
            </button>
          </nav>
        </div>
      </div>
    </header>
  );
}

const Header: React.FC = () => {
  const username = localStorage.getItem("username");
  const token = localStorage.getItem("token");
  const isLoggedIn = !!username && !!token;
  if (!isLoggedIn)
    { return <LayoutNoLoggedIn />;}
  else { return <LayoutLoggedIn/> }
  
};

export default Header;

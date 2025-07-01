import { Link } from "react-router-dom";
import { useState, useEffect } from "react";
import { fetchUserProfile } from "../components/utils/getUserData";

const Login = () => {

  if (localStorage.getItem("username") && localStorage.getItem("token")) {
    window.location.href = "/menu";
  }

  const [username, setUsername] = useState("");
  const [password, setPassword] = useState("");
  const [error, setError] = useState("");
  const [success, setSuccess] = useState("");
  const [isLoading, setIsLoading] = useState(false);

  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
      if (event.key === 'Enter') {
        handleLogin();
      }
    };

    window.addEventListener("keydown", handleKeyDown);
    return () => window.removeEventListener("keydown", handleKeyDown);
  }, [username, password]);

  const handleLogin = async () => {
    if (!username || !password) {
      setError("Por favor, ingresa tu nombre de usuario y contraseña");
      return;
    }

    setIsLoading(true);
    setError("");
    
    try {
      const response = await fetch("/api/auth/login", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({ username, password, oauth: 0 }),
      });

      const data = await response.json();
      
      if (!response.ok) {
        throw new Error(data.error || "Error en el inicio de sesión");
      }

      const profileResponse = await fetchUserProfile();
      localStorage.setItem("token", data.token);
      localStorage.setItem("username", profileResponse.username);
      
      setSuccess("¡Inicio de sesión exitoso!");
      setTimeout(() => window.location.href = "/menu", 1000);
      
    } catch (error) {
      console.error("Login error:", error);
      setError(error instanceof Error ? error.message : "Error desconocido");
    } finally {
      setIsLoading(false);
    }
  };

  const handleGoogleLogin = () => {
    window.location.href = "/api/auth/google";
  };

  return (
    <div className="relative min-h-screen text-white">
      <div className="relative z-20 flex items-center justify-center min-h-screen px-4 sm:px-6 lg:px-8">
        <div className="w-full max-w-md bg-gray-800/90 p-8 rounded-xl border border-gray-700 backdrop-blur-sm">
          <div className="text-center mb-8">
            <h2 className="text-3xl font-bold text-white mb-2">
              Iniciar sesión
            </h2>
            <p className="text-gray-400">
              Accede a tu cuenta para comenzar a jugar
            </p>
          </div>

          {error && (
            <div className="mb-4 p-3 bg-red-500/20 text-red-300 rounded-lg border border-red-500/30">
              {error}
            </div>
          )}
          {success && (
            <div className="mb-4 p-3 bg-green-500/20 text-green-300 rounded-lg border border-green-500/30">
              {success}
            </div>
          )}

          <div className="space-y-5">
            <div>
              <label htmlFor="username" className="block text-sm font-medium text-gray-300 mb-2">
                Nombre de usuario
              </label>
              <input
                type="text"
                id="username"
                value={username}
                onChange={(e) => setUsername(e.target.value)}
                className="w-full p-3 bg-gray-700/80 text-white rounded-lg border border-gray-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                placeholder="Tu nombre de usuario"
                disabled={isLoading}
              />
            </div>

            <div>
              <label htmlFor="password" className="block text-sm font-medium text-gray-300 mb-2">
                Contraseña
              </label>
              <input
                type="password"
                id="password"
                value={password}
                onChange={(e) => setPassword(e.target.value)}
                className="w-full p-3 bg-gray-700/80 text-white rounded-lg border border-gray-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                placeholder="Tu contraseña"
                disabled={isLoading}
              />
            </div>

            <button
              onClick={handleLogin}
              disabled={isLoading}
              className={`w-full py-3 rounded-lg font-medium transition ${isLoading 
                ? 'bg-blue-600/50 cursor-not-allowed' 
                : 'bg-blue-600 hover:bg-blue-700'}`}
            >
              {isLoading ? 'Cargando...' : 'Iniciar sesión'}
            </button>
          </div>

          {/* Separador */}
          <div className="flex items-center my-6">
            <div className="flex-grow border-t border-gray-600"></div>
            <span className="mx-4 text-gray-400 text-sm">O</span>
            <div className="flex-grow border-t border-gray-600"></div>
          </div>
            <button
            onClick={handleGoogleLogin}
            disabled={isLoading}
            className="w-full py-3 bg-gray-700 hover:bg-gray-600 rounded-lg flex items-center justify-center gap-2 transition"
            >
            <img src="/login/google.png" alt="Google Logo" className="w-5 h-5" />
            <span>Continuar con Google</span>
            </button>

          <div className="mt-6 text-center text-sm">
            <span className="text-gray-400">¿No tienes cuenta? </span>
            <Link
              to="/signup"
              className="text-blue-400 hover:text-blue-300 hover:underline transition"
            >
              Regístrate aquí
            </Link>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Login;
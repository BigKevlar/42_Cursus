import { useState, useEffect } from "react";
import { Link } from "react-router-dom";

const Signup = () => {

  if (localStorage.getItem("username") && localStorage.getItem("token")) {
    window.location.href = "/menu";
  }

  const [formData, setFormData] = useState({
    email: "",
    username: "",
    password: "",
    confirmPassword: ""
  });
  const [error, setError] = useState("");
  const [success, setSuccess] = useState("");
  const [isLoading, setIsLoading] = useState(false);

  useEffect(() => {
    const handleKeyDown = (event: KeyboardEvent) => {
      if (event.key === 'Enter') {
        handleRegister();
      }
    };

    window.addEventListener("keydown", handleKeyDown);
    return () => window.removeEventListener("keydown", handleKeyDown);
  }, [formData]); // Dependencias actualizadas

  const handleChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const { name, value } = e.target;
    setFormData(prev => ({
      ...prev,
      [name]: value
    }));
  };

  const handleRegister = async () => {
    setError("");
    setSuccess("");

    // Validaciones
    if (!formData.username || !formData.password || !formData.email || !formData.confirmPassword) {
      setError("Por favor, completa todos los campos");
      return;
    }

    if (formData.password !== formData.confirmPassword) {
      setError("Las contraseñas no coinciden");
      return;
    }

    setIsLoading(true);

    try {
      const response = await fetch("/api/auth/signup", {
        method: "POST",
        headers: { "Content-Type": "application/json" },
        body: JSON.stringify({
          email: formData.email,
          username: formData.username,
          password: formData.password,
          oauth: 0
        }),
      });

      const data = await response.json();
      
      if (!response.ok) {
        throw new Error(data.error || "Error al registrar el usuario");
      }

      setSuccess("¡Registro exitoso! Redirigiendo...");
      setTimeout(() => {
        window.location.href = "/login";
      }, 1500);
      
    } catch (error) {
      console.error("Registration error:", error);
      setError(error instanceof Error ? error.message : "Error desconocido");
    } finally {
      setIsLoading(false);
    }
  };

  const handleGoogleSignup = () => {
    window.location.href = "/api/auth/google";
  };

  return (
    <div className="relative min-h-screen text-white">


      {/* Contenido principal */}
      <div className="relative z-20 flex items-center justify-center min-h-screen px-4 sm:px-6 lg:px-8">
        <div className="w-full max-w-md bg-gray-800/90 p-8 rounded-xl border border-gray-700 backdrop-blur-sm">
          <div className="text-center mb-8">
            <h2 className="text-3xl font-bold text-white mb-2">
              Crear cuenta
            </h2>
            <p className="text-gray-400">
              Únete a la comunidad de ft_trascendence
            </p>
          </div>

          {/* Mensajes de estado */}
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

          {/* Formulario */}
          <div className="space-y-5">
            <div>
              <label htmlFor="email" className="block text-sm font-medium text-gray-300 mb-2">
                Correo electrónico
              </label>
              <input
                type="text"
                id="email"
                name="email"
                value={formData.email}
                onChange={handleChange}
                className="w-full p-3 bg-gray-700/80 text-white rounded-lg border border-gray-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                placeholder="Necesario para recuperar la cuenta"
                disabled={isLoading}
              />
            </div>
            <div>
              <label htmlFor="username" className="block text-sm font-medium text-gray-300 mb-2">
                Nombre de usuario
              </label>
              <input
                type="text"
                id="username"
                name="username"
                value={formData.username}
                onChange={handleChange}
                className="w-full p-3 bg-gray-700/80 text-white rounded-lg border border-gray-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                placeholder="Elige un nombre de usuario"
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
                name="password"
                value={formData.password}
                onChange={handleChange}
                className="w-full p-3 bg-gray-700/80 text-white rounded-lg border border-gray-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                placeholder="Crea una contraseña segura"
                disabled={isLoading}
              />
            </div>

            <div>
              <label htmlFor="confirmPassword" className="block text-sm font-medium text-gray-300 mb-2">
                Confirmar contraseña
              </label>
              <input
                type="password"
                id="confirmPassword"
                name="confirmPassword"
                value={formData.confirmPassword}
                onChange={handleChange}
                className="w-full p-3 bg-gray-700/80 text-white rounded-lg border border-gray-600 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:border-transparent"
                placeholder="Repite tu contraseña"
                disabled={isLoading}
              />
            </div>

            <button
              onClick={handleRegister}
              disabled={isLoading}
              className={`w-full py-3 rounded-lg font-medium transition ${isLoading 
                ? 'bg-blue-600/50 cursor-not-allowed' 
                : 'bg-blue-600 hover:bg-blue-700'}`}
            >
              {isLoading ? 'Registrando...' : 'Crear cuenta'}
            </button>
          </div>

          {/* Separador */}
          <div className="flex items-center my-6">
            <div className="flex-grow border-t border-gray-600"></div>
            <span className="mx-4 text-gray-400 text-sm">O</span>
            <div className="flex-grow border-t border-gray-600"></div>
          </div>

          {/* Registro con Google */}
          <button
            onClick={handleGoogleSignup}
            disabled={isLoading}
            className="w-full py-3 bg-gray-700 hover:bg-gray-600 rounded-lg flex items-center justify-center gap-2 transition"
            >
            <img src="/login/google.png" alt="Google Logo" className="w-5 h-5" />
            <span>Continuar con Google</span>
            </button>

          {/* Enlace a login */}
          <div className="mt-6 text-center text-sm">
            <span className="text-gray-400">¿Ya tienes cuenta? </span>
            <Link
              to="/login"
              className="text-blue-400 hover:text-blue-300 hover:underline transition"
            >
              Inicia sesión
            </Link>
          </div>
        </div>
      </div>
    </div>
  );
};

export default Signup;
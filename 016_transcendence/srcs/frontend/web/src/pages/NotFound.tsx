import React from "react";
import { Link } from "react-router-dom";
import { Home } from "lucide-react";

const NotFound: React.FC = () => {
  
  return (
    <div className="flex flex-col items-center justify-center min-h-screen bg-gradient-to-br from-gray-900 via-blue-950 to-indigo-950 py-12 px-4 sm:px-6 lg:px-8 text-center">
      <div className="max-w-md bg-gray-800/60 backdrop-blur-sm border border-gray-700 rounded-xl p-8 shadow-xl">
        <h1 className="text-8xl font-bold text-transparent bg-clip-text bg-gradient-to-r from-blue-400 via-indigo-400 to-purple-500 mb-6">
          404
        </h1>
        
        <div className="mb-6 relative">
          <svg 
            xmlns="http://www.w3.org/2000/svg" 
            viewBox="0 0 200 100" 
            className="w-full h-auto"
          >
            {/* Border gradient */}
            <defs>
              <linearGradient id="borderGradient" x1="0%" y1="0%" x2="0%" y2="100%">
                <stop offset="0%" stopColor="rgba(99, 102, 241, 0.4)" />
                <stop offset="50%" stopColor="rgba(255, 255, 255, 0.15)" />
                <stop offset="100%" stopColor="rgba(99, 102, 241, 0.4)" />
              </linearGradient>
            </defs>
            
            {/* Background */}
            <rect width="200" height="100" fill="#1f2937" rx="4" />
            
            {/* Border */}
            <rect 
              x="3" 
              y="3" 
              width="193"
              height="94" 
              fill="none" 
              stroke="url(#borderGradient)" 
              strokeWidth="1"
              rx="3"
            />
            
            {/* Center top line */}
            <line x1="100" y1="5" x2="100" y2="47" stroke="rgba(255,255,255,0.2)" strokeWidth="1" strokeDasharray="3" />

            {/* Center bottom line */}
			<line x1="100" y1="56" x2="100" y2="97" stroke="rgba(255,255,255,0.2)" strokeWidth="1" strokeDasharray="3" />

            {/* Center */}
			<circle cx="100" cy="50" r="3.5" fill="none" stroke="rgba(255,255,255,0.2)" strokeWidth="0.7" />

			{/* Center dot */}
			<circle cx="100" cy="50" r="0.5" fill="rgba(255,255,255,0.2)" />

            {/* Paddles */}
            <rect x="10" y="25" width="3" height="30" fill="#6366f1" rx="2" />
            <rect x="185" y="45" width="3" height="30" fill="#6366f1" rx="2" />
            
            {/* Ball */}
            <circle cx="150" cy="50" r="2" fill="white" />
          </svg>
        </div>
        
        <h2 className="text-xl text-white font-semibold mb-4">
        ¡Página no encontrada!
        </h2>
        
        <p className="text-gray-300 mb-8">
        Parece que esta página está fuera del campo de juego
        </p>
        
        <Link 
          to="/" 
          className="inline-flex items-center px-5 py-2 bg-blue-600 hover:bg-blue-700 text-white font-medium rounded-lg transition-colors duration-300"
        >
          <Home className="mr-2 h-5 w-5" />
          Volver a la Página Principal
        </Link>
      </div>
    </div>
  );
}

export default NotFound;
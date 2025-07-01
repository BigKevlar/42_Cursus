import React from 'react';
import { Zap, ArrowLeft } from "lucide-react";
import { Link } from "react-router-dom";

const Doom: React.FC = () => {
    return (
        <div className="relative min-h-screen text-white overflow-hidden">
            {/* Contenido principal */}
            <div className="relative z-20 min-h-screen flex flex-col">
                {/* Barra superior */}
                <div className="bg-gray-900/80 border-b border-gray-700 p-4 flex justify-between items-center">
                    <Link 
                        to="/menu" 
                        className="flex items-center text-blue-400 hover:text-blue-300 transition"
                    >
                        <ArrowLeft className="mr-2" size={20} />
                        Volver al menú
                    </Link>
                    <div className="flex items-center">
                        <Zap className="text-yellow-400 mr-2" size={20} />
                        <span className="font-mono text-sm">DOOM MODE</span>
                    </div>
                </div>

                {/* Contenedor del juego con efecto CRT */}
                <div className="flex-grow flex items-center justify-center p-4">
                    <div className="relative crt-effect">
                        <div className="crt-overlay"></div>
                        <iframe
                            src="https://dos.zone/doom-dec-1993/"
                            width="1280"
                            height="720"
                            title="DOOM (1993)"
                            className="rounded-lg border-2 border-red-900/50 shadow-lg shadow-red-900/20"
                            allowFullScreen
                        ></iframe>
                    </div>
                </div>

                {/* Footer retro */}
                <div className="bg-gray-900/80 border-t border-gray-700 p-3 text-center text-xs text-gray-400 font-mono">
                    <p>WARNING: DEMONIC ACTIVITY DETECTED | STATUS: CONTAINED | PLAYER: {localStorage.getItem('username') || 'UNKNOWN'}</p>
                </div>
            </div>

            {/* Estilos CSS para efecto CRT */}
            <style>{`
                .crt-effect {
                    position: relative;
                    overflow: hidden;
                }
                .crt-effect::before {
                    content: "";
                    position: absolute;
                    top: 0;
                    left: 0;
                    right: 0;
                    bottom: 0;
                    background: linear-gradient(
                        rgba(18, 16, 16, 0) 50%, 
                        rgba(0, 0, 0, 0.25) 50%
                    );
                    background-size: 100% 4px;
                    z-index: 10;
                    pointer-events: none;
                }
                .crt-overlay {
                    position: absolute;
                    top: 0;
                    left: 0;
                    right: 0;
                    bottom: 0;
                    background: 
                        radial-gradient(
                            circle at center,
                            transparent 0%,
                            rgba(255, 0, 0, 0.05) 100%
                        );
                    z-index: 10;
                    pointer-events: none;
                    mix-blend-mode: overlay;
                }
                iframe {
                    filter: brightness(1.1) contrast(1.1) saturate(1.1);
                }
            `}</style>
        </div>
    );
};

export default Doom;
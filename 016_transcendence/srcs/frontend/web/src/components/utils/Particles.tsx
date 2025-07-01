import React, { useState, useEffect } from 'react';

interface Particle {
  id: number;
  x: number;
  y: number;
  size: number;
  speed: number;
}

const Particles: React.FC = () => {
  const [particles, setParticles] = useState<Array<Particle>>([]);

  useEffect(() => {
    const newParticles = Array.from({ length: 100 }, (_, i) => ({
      id: i,
      x: Math.random() * 100,
      y: Math.random() * 100,
      size: Math.random() * 4 + 1,
      speed: Math.random() * 0.5 + 0.1
    }));
    
    setParticles(newParticles);
    
    const interval = setInterval(() => {
      setParticles(prevParticles => 
        prevParticles.map(particle => ({
          ...particle,
          y: particle.y - particle.speed < 0 ? 100 : particle.y - particle.speed
        }))
      );
    }, 50);
    
    return () => clearInterval(interval);
  }, []);

  return (
    <>
      {particles.map(particle => (
        <div 
          key={particle.id}
          className="absolute rounded-full bg-blue-500 opacity-20"
          style={{
            left: `${particle.x}%`,
            top: `${particle.y}%`,
            width: `${particle.size}px`,
            height: `${particle.size}px`,
            transition: 'top 0.5s linear'
          }}
        />
      ))}
    </>
  );
};

export default Particles;
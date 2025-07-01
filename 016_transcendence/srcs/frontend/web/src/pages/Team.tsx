import React from "react";
  const teamMembers = [
    {
      name: "Victor Javier Zurera Del Valle",
      login: "vzurera-",
      role: "API Gateway e infraestructura de Docker",
      description: "Desarrollo de la estructura de contenedores, seguridad y proxy en Gateway.",
      github: "Kobayashi82",
      skills: ["Node.js", "SQLite"],
      image: "/team/vzurera-.png",
      linkedin: "victor-javier-zurera-del-valle"
    },
    {
      name: "Juan Carlos Martos Vergara",
      login: "jmartos-",
      role: "Frontend y microservicios",
      description: "Desarrollo del frontend, con enfoque en menús y juego principal, y puesta en marcha de los microservicios del proyecto.",
      github: "CyberKevlar",
      skills: ["TypeScript", "Tailwind CSS"],
      image: "/team/jmartos-.png",
      linkedin: "juan-carlos-martos-vergara"
    },
    {
      name: "Jose Maria Gomez Cardenas",
      login: "jose-mgo",
      role: "Backend",
      description: "Desarrollo del backend en general del proyecto y creacion del juego secundario.",
      github: "pepe587",
      skills: ["React", "WebSockets"],
      image: "/team/jose-mgo.png",
      linkedin: "josé-maría-gómez-cárdenas-0884072a8"
    },
    {
      name: "Pablo Rando Alcala",
      login: "prando-a",
      role: "Backend y autenticaciones",
      description: "Desarrollo del backend en la parte de autenticaciones, registro de usuarios y base de datos.",
      github: "prando-a",
      skills: ["Game Physics", "OAuth"],
      image: "/team/prando-a.png",
      linkedin: "pablo-rando-alcalá-bb7696290"
    },
    {
      name: "Alejandro Rosas Jaime",
      login: "arosas-j",
      role: "Frontend y debuger",
      description: "Frontend en general, pero sobre todo encargado de buscar fallos y errores en el proyecto.",
      github: "arosas-j",
      skills: ["Docker", "Nginx"],
      image: "/team/arosas-j.png",
      linkedin: "alejandro-rosas-jaime"
    }
  ];
const Team: React.FC = () => {


  return (
    <div className="relative min-h-screen text-white">


      {/* Contenido principal */}
      <div className="relative z-20 max-w-7xl mx-auto px-4 sm:px-6 lg:px-8 py-16">
        <h1 className="text-5xl font-extrabold mb-12 text-center">
          Conoce al equipo de <span className="text-blue-400">ft_trascendence</span>
        </h1>
        
        <div className="bg-gray-800/80 rounded-xl border border-gray-700 overflow-hidden">
          <div className="grid md:grid-cols-7 gap-0">
            {/* Encabezados de la tabla */}
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">Foto</div>
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">Nombre</div>
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">42_login</div>
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">Rol</div>
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">Descripción</div>
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">GitHub</div>
            <div className="bg-gray-900 p-4 font-bold border-b border-gray-700 text-center">Linkedin</div>
            
            {/* Filas de datos */}
            {teamMembers.map((member, index) => (
              <React.Fragment key={index}>
                <div className="p-4 border-b border-gray-700 flex items-center justify-center ">
                  <img src={member.image} alt={member.name} className="w-32 h-32 rounded-full object-cover" />
                </div>
                <div className="p-4 border-b border-gray-700 flex justify-center items-center text-center">
                  {member.name}
                </div>
                <div className="p-4 border-b border-gray-700 flex justify-center items-center text-center">
                  {member.login}
                </div>
                <div className="p-4 border-b border-gray-700 flex justify-center items-center text-center">
                  <span className="bg-green-600/50 px-3 py-1 rounded-full text-sm">
                    {member.role}
                  </span>
                </div>
                <div className="p-4 border-b border-gray-700 flex justify-center items-center text-center">
                  {member.description}
                </div>
                <div className="p-4 border-b border-gray-700 flex justify-center items-center text-center">
                  <a 
                    href={`https://github.com/${member.github}`} 
                    target="_blank" 
                    rel="noopener noreferrer"
                    className="text-blue-400 hover:text-blue-300 transition"
                  >
                    <img src="../../team/github.png" alt="GitHub" className="w-8 h-8 inline mr-1" />
                    <br />
                    @{member.github}
                  </a>
                </div>
                <div className="p-4 border-b border-gray-700 flex justify-center items-center text-center">
                  <a 
                    href={`https://www.linkedin.com/in/${member.linkedin}`}
                    target="_blank" 
                    rel="noopener noreferrer"
                    className="text-blue-400 hover:text-blue-300 transition"
                  >
                    <img src="../../team/linkedin.png" alt="LinkedIn" className="w-8 h-8 inline mr-1" />
                    <br />
                    @{member.linkedin}
                  </a>
                </div>
              </React.Fragment>
            ))}
          </div>
        </div>

        {/* Sección de habilidades del equipo */}
        <div className="mt-16">
          <h2 className="text-3xl font-bold mb-8 text-center">Nuestras habilidades colectivas</h2>
          <div className="flex flex-wrap justify-center gap-4">
            {Array.from(new Set(teamMembers.flatMap(member => member.skills))).map((skill, index) => (
              <div 
                key={index} 
                className="bg-blue-600/50 px-4 py-2 rounded-full border border-blue-400/30"
              >
                {skill}
              </div>
            ))}
          </div>
        </div>

        {/* Mensaje final */}
        <div className="mt-16 text-center max-w-3xl mx-auto">
          <p className="text-xl mb-6">
            Somos estudiantes de 42 Málaga apasionados por el desarrollo de software.
            Este proyecto representa nuestro esfuerzo conjunto para crear una experiencia
            de juego web moderna y divertida.
          </p>
          <p className="text-blue-400 font-medium">
            ¡Gracias por probar ft_trascendence!
          </p>
        </div>
      </div>
    </div>
  );
};

export default Team;
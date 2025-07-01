import React from "react";

interface Match {
  p1?: string;
  p2?: string;
  winner?: string;
}

interface Side {
  [key: string]: Match;
}

interface TournamentData {
  id: number;
  nextmatch?: {
    round: string;
    side: string;
    match: string | null;
    p1: string;
    p2: string;
  };
  [key: string]: any;
}

interface TournamentBracketProps {
  tournamentData: TournamentData | undefined;
}

const TournamentBracket: React.FC<TournamentBracketProps> = ({ tournamentData }) => {
  if (!tournamentData) {
    return <div className="text-center">No hay datos del torneo disponibles.</div>;
  }

  const roundKeys = Object.keys(tournamentData)
    .filter(key => key.startsWith('round'))
    .sort((a, b) => {
      const numA = parseInt(a.replace('round', ''));
      const numB = parseInt(b.replace('round', ''));
      return numA - numB;
    });

  const lastRound = roundKeys[roundKeys.length - 1];
  const champion = tournamentData[lastRound]?.final?.winner;

  let tournamentSize = 0;
  if (roundKeys.length === 2) tournamentSize = 4;
  else if (roundKeys.length === 3) tournamentSize = 8;
  else if (roundKeys.length === 4) tournamentSize = 16;

  const getContainerWidthClass = () => {
    switch (tournamentSize) {
      case 4: return "max-w-2xl";
      case 8: return "max-w-3xl";
      case 16: return "max-w-4xl";
      default: return "max-w-2xl";
    }
  };

  const renderMatch = (round: string, side: string, matchKey: string, match: Match) => {
    const isCurrentMatch = tournamentData.nextmatch && 
                        tournamentData.nextmatch.round === round && 
                        tournamentData.nextmatch.side === side && 
                        (tournamentData.nextmatch.match === matchKey || 
                         (tournamentData.nextmatch.match === null && matchKey === 'final'));
                        
    const isCompleted = match.winner !== undefined;
    
    const matchBorderClass = isCurrentMatch 
      ? "border-pink-500/80 border-2" 
      : isCompleted 
        ? "border-green-500/50" 
        : "border-gray-700";

    const matchBgClass = isCurrentMatch
      ? "bg-gradient-to-r from-pink-900/30 to-blue-900/30"
      : isCompleted
        ? "bg-gradient-to-r from-green-900/20 to-blue-900/20"
        : "bg-gray-800/40";
    
    const p1Display = match.p1 || "Pendiente";
    const p2Display = match.p2 || "Pendiente";
    
    const p1Class = match.p1 
      ? (match.winner === match.p1 ? 'bg-green-900/30 text-green-300 font-bold' : '') 
      : 'text-gray-500/80 italic';
      
    const p2Class = match.p2 
      ? (match.winner === match.p2 ? 'bg-green-900/30 text-green-300 font-bold' : '') 
      : 'text-gray-500/80 italic';

    return (
      <div className={`flex flex-row ${matchBgClass} rounded-md border ${matchBorderClass} overflow-hidden shadow-md`}>
        <div 
          className={`py-2 px-3 text-sm font-medium flex-1 ${p1Class}`}
        >
          {p1Display}
        </div>
        <div className="w-px self-stretch bg-gray-700" />
        <div 
          className={`py-2 px-3 text-sm font-medium flex-1 ${p2Class}`}
        >
          {p2Display}
        </div>
      </div>
    );
  };

  const renderFinalMatch = (roundKey: string) => {
    const roundData = tournamentData[roundKey];
    if (!roundData.final) return null;

    return (
      <div className="flex flex-col items-center">
        <div className="text-xs text-gray-400 uppercase tracking-wider mb-2">Final</div>
        <div className="w-64">
          {renderMatch(roundKey, 'final', 'final', roundData.final)}
        </div>

        {champion && (
          <div className="mt-4 text-center">
            <div className="px-4 py-2 bg-yellow-900/30 rounded-lg border border-yellow-500/50">
              <div className="font-bold text-xs uppercase text-gray-400 mb-1">Campeón</div>
              <div className="font-bold text-xl text-yellow-300">{champion}</div>
            </div>
          </div>
        )}
      </div>
    );
  };

  const renderSide = (roundKey: string, side: string, sideData: Side) => {
    const matchKeys = Object.keys(sideData).sort();
    const isLeftSide = side === 'left';
    
    return (
      <div className={`flex flex-col ${isLeftSide ? 'items-end pr-6' : 'items-start pl-6'} space-y-8`}>
        {matchKeys.map(matchKey => {
          const matchIndex = parseInt(matchKey.replace('match', ''));
          const className = `w-64 relative match-container ${isLeftSide ? 'left' : 'right'} match-${matchIndex}`;
          
          return (
            <div key={`${roundKey}-${side}-${matchKey}`} className={className}>
              {renderMatch(roundKey, side, matchKey, sideData[matchKey])}
              
            </div>
          );
        })}
      </div>
    );
  };

  const renderRound = (roundKey: string) => {
    const roundData = tournamentData[roundKey];
    const roundNumber = parseInt(roundKey.replace('round', ''));
    
    return (
      <div className="mb-12 relative" key={roundKey}>
        <div className="text-center mb-6">
          <span className="inline-block px-3 py-1 bg-gray-800/50 text-gray-300 rounded-full text-sm font-medium">
            Ronda {roundNumber}
          </span>
        </div>
        
        <div className="flex justify-center">
          {roundData.final && !roundData.left && !roundData.right && (
            renderFinalMatch(roundKey)
          )}
          
          {roundData.left && roundData.right && (
            <div className="flex justify-center w-full">
              <div className="flex-1 flex justify-end">
                {renderSide(roundKey, 'left', roundData.left)}
              </div>
              
              {roundData.final && (
                <div className="mx-8 flex items-center justify-center">
                  {renderFinalMatch(roundKey)}
                </div>
              )}
              
              <div className="flex-1 flex justify-start">
                {renderSide(roundKey, 'right', roundData.right)}
              </div>
            </div>
          )}
        </div>
      </div>
    );
  };

  return (
    <div className={`w-full mx-auto ${getContainerWidthClass()} py-6 bracket-container`}>
      <style>{`
        /* CSS para los conectores del bracket */
        .bracket-container {
          position: relative;
        }
        
        .match-container {
          position: relative;
        }
        
        /* Estilos para el resaltado del partido actual */
        .bracket-container .match-current {
          animation: pulsate 2s infinite;
        }
        
        @keyframes pulsate {
          0% { box-shadow: 0 0 0 0 rgba(236, 72, 153, 0.4); }
          70% { box-shadow: 0 0 0 10px rgba(236, 72, 153, 0); }
          100% { box-shadow: 0 0 0 0 rgba(236, 72, 153, 0); }
        }
      `}</style>
      
      <div className="space-y-16">
        {roundKeys.map((roundKey) => (
          <React.Fragment key={roundKey}>
            {renderRound(roundKey)}
          </React.Fragment>
        ))}
      </div>
    </div>
  );
};

export default TournamentBracket;
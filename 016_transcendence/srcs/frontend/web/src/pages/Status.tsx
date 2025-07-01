import { useState, useEffect, useRef, useMemo } from "react";
import { ArrowLeft, RefreshCw, CheckCircle, XCircle, AlertTriangle, Server } from "lucide-react";
import { Link } from "react-router-dom";

const AVAILABLE_MICROSERVICES = ["auth", "game", "sprinter", "tournament"];

interface Service {
  status: string;
  statusCode?: number;
  responseTime: string;
}

interface ServicesType { [key: string]: Service; }

let cachedData: { status: ServerStatus | null; lastUpdated: Date | null; } = { status: null, lastUpdated: null }

interface ServerStatus {
  gateway: {
    status: string;
    uptime: number;
    timestamp: string;
    responseTime?: string;
  }
  services: ServicesType;
}

const ServerStatusPage: React.FC = () => {
  const [status, setStatus] = useState<ServerStatus | null>(cachedData.status);
  const [loading, setLoading] = useState<boolean>(!cachedData.status);
  const [refreshing, setRefreshing] = useState<boolean>(false);
  const [error, setError] = useState<string | null>(null);
  const [lastUpdated, setLastUpdated] = useState<Date | null>(cachedData.lastUpdated);
  const isMounted = useRef<boolean>(true);

  useEffect(() => {
    isMounted.current = true;
    return () => { isMounted.current = false; }
  }, []);

  const fetchServerStatus = async (isRefreshing = false) => {
    if (!isMounted.current) return;

    try {
      if (isRefreshing) setRefreshing(true);
      else 				setLoading(true);

      const startTime = performance.now();
      const response = await fetch("/api/health", { signal: AbortSignal.timeout(4000), headers: { "Cache-Control": "no-cache, no-store, must-revalidate", Pragma: "no-cache", Expires: "0", }, });
      const endTime = performance.now();
      const responseTimeMs = Math.round(endTime - startTime);
      const formattedResponseTime = `${responseTimeMs} ms`;

	  if (!response.ok) throw new Error(`Status: ${response.status}`);

	  const data = await response.json();
      if (data.gateway) data.gateway.responseTime = formattedResponseTime;

      setStatus(data);
      cachedData.status = data;
      setError(null);

      const now = new Date();
      setLastUpdated(now);
      cachedData.lastUpdated = now;
    } catch (error) {
      const isRateLimitError = error instanceof Error && (error.message.includes("429") || error.message.includes("Too Many Requests") || error.message.includes("rate limit"));

      if (isRateLimitError) setError("Límite de solicitudes excedido. Por favor, inténtalo de nuevo más tarde.");
      else {
        const downServices: ServicesType = {}
        AVAILABLE_MICROSERVICES.forEach(serviceName => { downServices[serviceName] = { status: "Down", responseTime: "N/A" }});

        const downStatus = {
          gateway: {
            status: "Down",
            uptime: 0,
            timestamp: new Date().toISOString(),
            responseTime: "N/A",
          },
          services: downServices
        }
        if (isRefreshing || !status) { setStatus(downStatus); cachedData.status = downStatus; }

        const errorMessage = error instanceof Error ? error.message : "Error desconocido";
        setError(`Gateway no disponible: ${errorMessage}`);
      }
      
      const now = new Date();
      setLastUpdated(now);
      cachedData.lastUpdated = now;
    } finally {
      if (!isMounted.current) return;

	  setLoading(false);
      setRefreshing(false);
    }
  }

  const handleManualRefresh = () => { fetchServerStatus(true); }
  useEffect(() => { fetchServerStatus(); }, []);

  const formatUptime = (seconds: number): string => {
    const days = Math.floor(seconds / 86400);
    const hours = Math.floor((seconds % 86400) / 3600);
    const minutes = Math.floor((seconds % 3600) / 60);
    const remainingSeconds = Math.floor(seconds % 60);

    return `${days}d ${hours}h ${minutes}m ${remainingSeconds}s`;
  }

  const getStatusColor = (status: string): string => {
    switch (status?.toLowerCase()) {
      case "up":
      case "healthy":
        return "text-green-500";
      case "warning":
      case "degraded":
        return "text-yellow-500";
      case "down":
      case "critical":
      case "error":
        return "text-red-500";
      case "loading":
        return "text-indigo-400";
      default:
        return "text-gray-500";
    }
  }

  const isServiceDown = (status: string): boolean => { return ["down", "critical", "error"].includes(status?.toLowerCase()); }

  const getStatusIcon = (status: string) => {
    switch (status?.toLowerCase()) {
      case "up":
      case "healthy":
        return <CheckCircle className="h-5 w-5 text-green-500" />;
      case "warning":
      case "degraded":
        return <AlertTriangle className="h-5 w-5 text-yellow-500" />;
      case "down":
      case "critical":
      case "error":
        return <XCircle className="h-5 w-5 text-red-500" />;
      case "loading":
        return <RefreshCw className="h-5 w-5 text-indigo-400 animate-spin" />;
      default:
        return <AlertTriangle className="h-5 w-5 text-gray-500" />;
    }
  }

  const translateStatus = (status: string): string => {
    switch (status?.toLowerCase()) {
      case "up":
        return 'Activo';
      case "down":
        return 'Caído';
      case "loading":
        return 'Cargando';
      case "warning":
        return 'Aviso';
      case "degraded":
        return 'Degradado';
      case "critical":
        return 'Crítico';
      case "error":
        return 'Error';
      case "healthy":
        return 'Saludable';
      default:
        return status;
    }
  }

  const StatusBadge: React.FC<{ status: string }> = ({ status }) => {
    const textColor = getStatusColor(status);
    const icon = getStatusIcon(status);
    const translatedStatus = translateStatus(status);

    const bgColorClass = (() => {
      switch (status?.toLowerCase()) {
        case "up":
        case "healthy":
          return "bg-green-900/30 border-green-500/20";
        case "warning":
        case "degraded":
          return "bg-yellow-900/30 border-yellow-500/20";
        case "down":
        case "critical":
        case "error":
          return "bg-red-900/30 border-red-500/20";
        case "loading":
          return "bg-indigo-900/30 border-indigo-500/20";
        default:
          return "bg-gray-900/30 border-gray-500/20";
      }
    })();

    return (
      <span
        className={`inline-flex items-center gap-1 ${bgColorClass} ${textColor} text-xs font-medium px-2.5 py-1 rounded-full border`}
      >
        {icon}
        {translatedStatus}
      </span>
    );
  }

  const displayStatus = useMemo(() => {
    if (loading && !status && !cachedData.status) {
      const loadingServices: ServicesType = {}
      AVAILABLE_MICROSERVICES.forEach(service => { loadingServices[service] = { status: "Loading", responseTime: "..." }});

      return {
        gateway: {
          status: "Loading",
          uptime: 0,
          timestamp: new Date().toISOString(),
          responseTime: "...",
        },
        services: loadingServices,
      }
    }

    if (status) {
      const correctedStatus = { ...status }

      if (isServiceDown(correctedStatus.gateway.status)) {
        const downServices: ServicesType = {}

        AVAILABLE_MICROSERVICES.forEach(serviceName => { downServices[serviceName] = { status: "Down", responseTime: "N/A" }});
        correctedStatus.services = downServices;
      } else {
        if (correctedStatus.services) {
          Object.keys(correctedStatus.services).forEach(serviceName => {
            const service = correctedStatus.services[serviceName];
            if (isServiceDown(service.status) && service.responseTime !== "N/A") correctedStatus.services[serviceName] = { ...service, responseTime: "N/A" }
          });
        }
      }

      return correctedStatus;
    }

    return status || cachedData.status;
  }, [loading, status]);

  if (error && !displayStatus) {
    return (
      <div className="flex h-screen items-center justify-center bg-gray-900">
        <div className="text-center p-8 bg-gray-800 rounded-lg shadow-lg max-w-md">
          <XCircle className="h-12 w-12 text-red-500 mx-auto mb-4" />
          <h1 className="text-2xl font-bold text-red-400 mb-4">
            Error de conexión
          </h1>
          <p className="text-gray-300 mb-6">{error}</p>
          <div className="flex justify-center gap-4">
            <button
              onClick={() => fetchServerStatus()}
              className="w-full py-3 bg-indigo-600 hover:bg-indigo-700 text-white rounded-lg focus:outline-none focus:ring-2 focus:ring-indigo-500 flex items-center justify-center"
            >
              <RefreshCw className="h-4 w-4 mr-2" />
              Reintentar
            </button>
            <Link to="/" className="w-full py-3 bg-gray-700 hover:bg-gray-600 text-white rounded-lg focus:outline-none focus:ring-2 focus:ring-gray-500 flex items-center justify-center">
              <ArrowLeft className="h-4 w-4 mr-2" />
              Página Principal
            </Link>
          </div>
        </div>
      </div>
    );
  }

  if (!displayStatus) return null;

  return (
    <div className="flex items-center justify-center min-h-screen">
      <div className="w-full max-w-6xl p-8">

        <div className="flex flex-col md:flex-row justify-between items-center mb-8">
          <div>
            <div className="flex items-center">
              <h1 className="text-3xl font-semibold text-white mb-2">
                Estado del Servidor
              </h1>
              <div className="w-8 flex justify-center">
              <button
                onClick={handleManualRefresh}
                className="text-indigo-400 hover:text-indigo-300 transition-colors ml-8 p-2 rounded-full hover:bg-indigo-900/50 focus:outline-none"
                disabled={refreshing || loading}
              >
                <RefreshCw
                  className={`h-6 w-6 ${
                    refreshing || loading ? "animate-spin" : ""
                  }`}
                />
              </button>
              </div>
            </div>
            <span className="block mt-2 text-md font-normal text-indigo-400">
              Monitoreo en tiempo real
            </span>
          </div>
        </div>

        {/* Gateway Status Card */}
        <div className="bg-gray-800 rounded-xl border border-gray-700 overflow-hidden shadow-lg mb-8">
          <div className="p-6 border-b border-gray-700">
            <div className="flex items-center">
              <div className="w-12 h-12 bg-indigo-900/30 rounded-lg flex items-center justify-center mr-4">
                <Server size={24} className="text-indigo-400" />
              </div>
              <div>
                <h3 className="text-xl font-semibold text-white">
                  Gateway
                </h3>
                <p className="text-gray-400 text-sm">Servicio API Gateway</p>
              </div>
            </div>
          </div>

          <div className="overflow-x-auto">
            <table className="w-full">
              <thead className="bg-gray-700">
                <tr>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-400 uppercase tracking-wider w-1/3">
                    Tiempo Activo
                  </th>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-400 uppercase tracking-wider w-1/3">
                    Estado
                  </th>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-400 uppercase tracking-wider w-1/3">
                    Última Actualización
                  </th>
                </tr>
              </thead>
              <tbody>
                <tr className="bg-gray-800">
                  <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-300 font-mono">
                    {displayStatus.gateway.status.toLowerCase() === "loading"
                      ? "..."
                      : formatUptime(displayStatus.gateway.uptime)}
                  </td>
                  <td className="px-6 py-4 whitespace-nowrap text-sm">
                    <StatusBadge status={displayStatus.gateway.status} />
                  </td>
                  <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-300 font-mono">
                    {lastUpdated ? lastUpdated.toLocaleString().replace(",", "") : '...'}
                  </td>
                </tr>
              </tbody>
            </table>
          </div>
        </div>

        {/* Services Status Section */}
        <div className="bg-gray-800 rounded-xl border border-gray-700 overflow-hidden shadow-lg mb-8">
          <div className="p-6 border-b border-gray-700">
            <div className="flex items-center">
              <div className="w-12 h-12 bg-indigo-900/30 rounded-lg flex items-center justify-center mr-4">
                <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2" strokeLinecap="round" strokeLinejoin="round" className="text-indigo-400">
                  <path d="M8 5v4"></path>
                  <rect width="16" height="16" x="4" y="2" rx="2"></rect>
                  <path d="M2 10h4"></path>
                  <path d="M2 14h4"></path>
                  <path d="M18 5v4"></path>
                  <path d="M12 2v20"></path>
                </svg>
              </div>
              <div>
                <h2 className="text-xl font-semibold text-white">Microservicios</h2>
                <p className="text-gray-400 text-sm">Estado de todos los servicios backend</p>
              </div>
            </div>
          </div>

          <div className="overflow-x-auto">
            <table className="w-full">
              <thead className="bg-gray-700">
                <tr>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-400 uppercase tracking-wider w-1/3">
                    Servicio
                  </th>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-400 uppercase tracking-wider w-1/3">
                    Estado
                  </th>
                  <th className="px-6 py-3 text-left text-xs font-medium text-gray-400 uppercase tracking-wider w-1/3">
                    Tiempo de Respuesta
                  </th>
                </tr>
              </thead>
              <tbody className="divide-y divide-gray-700">
                {/* Display existing services */}
                {Object.entries(displayStatus.services)
                  .sort(([nameA], [nameB]) => {
                    const indexA = AVAILABLE_MICROSERVICES.indexOf(nameA);
                    const indexB = AVAILABLE_MICROSERVICES.indexOf(nameB);
                    return (indexA !== -1 ? indexA : 99) - (indexB !== -1 ? indexB : 99);
                  })
                  .map(([name, data]) => (
                    <tr key={name} className="bg-gray-800">
                      <td className="px-6 py-4 whitespace-nowrap">
                        <div className="flex items-center">
                          <div className="w-8 flex justify-center">
                            {getStatusIcon(data.status)}
                          </div>
                          <span className="text-sm font-medium text-white capitalize">
                            {name}
                          </span>
                        </div>
                      </td>
                      <td className="px-6 py-4 whitespace-nowrap text-sm">
                        <StatusBadge status={data.status} />
                      </td>
                      <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-300 font-mono">
                        {data.responseTime}
                      </td>
                    </tr>
                  )
                )}

                {displayStatus && displayStatus.gateway && displayStatus.gateway.status.toLowerCase() !== "down" &&
                  displayStatus.gateway.status.toLowerCase() !== "loading" &&
                  displayStatus.services && Object.keys(displayStatus.services).length > 0 &&
                  AVAILABLE_MICROSERVICES.map(serviceName => {
                    if (!displayStatus.services[serviceName]) {
                      return (
                        <tr key={serviceName} className="bg-gray-800">
                          <td className="px-6 py-4 whitespace-nowrap">
                            <div className="flex items-center">
                              <div className="w-8 flex justify-center">
                                {getStatusIcon("down")}
                              </div>
                              <span className="text-sm font-medium text-white capitalize">
                                {serviceName}
                              </span>
                            </div>
                          </td>
                          <td className="px-6 py-4 whitespace-nowrap text-sm">
                            <StatusBadge status="Down" />
                          </td>
                          <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-300 font-mono">
                            N/A
                          </td>
                        </tr>
                      );
                    }
                    return null;
                  }).filter(Boolean)}

                {displayStatus.gateway.status.toLowerCase() !== "down" &&
                  displayStatus.gateway.status.toLowerCase() !== "loading" &&
                  Object.keys(displayStatus.services).length === 0 && (
                    <tr className="bg-gray-800">
                      <td
                        colSpan={3}
                        className="px-6 py-8 text-center text-sm text-gray-400"
                      >
                        No hay información de servicios disponible
                      </td>
                    </tr>
                  )}
              </tbody>
            </table>
          </div>
        </div>
      </div>
    </div>
  );
}

export default ServerStatusPage;

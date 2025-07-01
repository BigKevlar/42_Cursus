"use strict";

const fp = require("fastify-plugin");
const httpProxy = require("@fastify/http-proxy");

function routeMatches(route, pattern) {
  if (route === pattern) return true;
  
  // Split into segments
  const routeSegments = route.split('/').filter(Boolean);
  const patternSegments = pattern.split('/').filter(Boolean);

  if (routeSegments.length !== patternSegments.length) return false;
  
  // Check segments
  for (let i = 0; i < routeSegments.length; i++) {
    // If pattern segment starts with :, it's a parameter
    if (patternSegments[i].startsWith(':')) continue;
    if (routeSegments[i] !== patternSegments[i]) return false;
  }
  
  return true;
}

const getAllowedHttpMethods = (routes) => {
  const defaultMethods = ["GET", "POST", "PUT", "DELETE", "PATCH", "OPTIONS"];

  // If no routes defined, use default methods
  if (!routes || Object.keys(routes).length === 0) return defaultMethods;

  const methods = new Set();

  methods.add("OPTIONS");

  // Add methods from service configurations
  for (const routeConfig of Object.values(routes)) {
    if (typeof routeConfig === "object" && routeConfig.method) {
      const methodArray = Array.isArray(routeConfig.method) ? routeConfig.method : [routeConfig.method];
      methodArray.forEach((method) => methods.add(method.toUpperCase()));
    }
  }

  // If no methods defined, use default methods
  if (methods.size <= 1) return defaultMethods;

  return Array.from(methods);
}

async function proxyPlugin(fastify) {

  const { services, routeMap } = fastify.config;
  const wsProxies = {}
  const activeConnections = new Map();

  // Add a preHandler hook to check allowed methods
  fastify.addHook("preHandler", async (request, reply) => {
    const url = request.url;
    const method = request.method;

    let prefix = null;
    let serviceName = null;
    
    // Find matching service prefix
    for (const [svcPrefix, svcName] of Object.entries(routeMap)) {
      if (url.startsWith(svcPrefix)) {
        prefix = svcPrefix;
        serviceName = svcName;
        break;
      }
    }

    // Not a proxied route, continue to next handler
    if (!serviceName || !services[serviceName]) return;

    // Get service and route configuration
    const service = services[serviceName];
    const routePath = url.substring(prefix.length).split("?")[0];

    let allowedMethods = null;
    let matchFound = false;

    // Check for exact route match
    if (service.routes && service.routes[routePath]) {
      const routeConfig = service.routes[routePath];
      matchFound = true;

      if (typeof routeConfig === "object" && routeConfig.method) {
        allowedMethods = Array.isArray(routeConfig.method) ? routeConfig.method.map((m) => m.toUpperCase()) : [routeConfig.method.toUpperCase()];
      }
    } else if (service.routes) {
      // Check for pattern matches (routes with parameters)
      for (const [pattern, routeConfig] of Object.entries(service.routes)) {
        if (routeMatches(routePath, pattern)) {
          matchFound = true;
          
          if (typeof routeConfig === "object" && routeConfig.method) {
            allowedMethods = Array.isArray(routeConfig.method) ? routeConfig.method.map((m) => m.toUpperCase()) : [routeConfig.method.toUpperCase()];
          }
          break;
        }
      }
    }

    // If route not found
    if (!matchFound && !service.routes["*"] && !service.routes["/*"]) {
      reply.code(404).send({
        statusCode: 404,
        message: `Route ${routePath} not found`,
      });
      return reply;
    }

    // If method not allowed
    if (allowedMethods && !allowedMethods.includes(method)) {
      reply.code(405).send({
        statusCode: 405,
        message: `This endpoint only accepts ${allowedMethods.join(", ")} requests`,
      });
      return reply;
    }
  });

  // Proxy
  for (const [serviceName, serviceConfig] of Object.entries(services)) {
    const { url: serviceUrl, prefix, routes = {}, proxyOptions = {}, wsEnabled = false, wsPath = prefix, timeout } = serviceConfig;
    const httpMethods = getAllowedHttpMethods(routes);

    // HTTP
    fastify.register(httpProxy, { upstream: serviceUrl, prefix: prefix, http2: false, httpMethods: httpMethods, timeout: timeout,
      replyOptions: {
        rewriteRequestHeaders: (req, headers) => {
          headers["x-forwarded-proto"] = req.protocol;
          headers["x-forwarded-host"] = req.headers.host;
          headers["x-source"] = "gateway";
          headers["x-target"] = serviceName;
          headers["x-request-id"] = `${req.ip.replace(/[.:]/g, '-')}_${req.url.replace(/[\/?.]/g, '-')}_${Date.now()}`;
          headers["x-gateway-timestamp"] = Date.now().toString();

          if (req.auth && req.auth.authenticated) {
            headers['x-user-id'] = req.auth.id.toString()
            headers['x-user-username'] = req.auth.username
          }

          if (proxyOptions.rewriteRequestHeaders) headers = proxyOptions.rewriteRequestHeaders(req, headers);
          return headers;
        },
      },
      ...proxyOptions,
    });

    // Websocket
    if (wsEnabled) {
      const parsedUrl = new URL(serviceUrl);
      wsProxies[wsPath] = {
        target: {
          host: parsedUrl.hostname,
          port: parsedUrl.port,
          protocol: parsedUrl.protocol
        },
        serviceName,
        serviceUrl
      }
    }
  }

  fastify.server.on('upgrade', (request, socket) => {
    const pathname = new URL(request.url, 'http://localhost').pathname;
    const matchingProxy = Object.entries(wsProxies).find(([path, _]) => pathname.replace(/^\/api/, '').startsWith(path));
    if (!matchingProxy) { socket.destroy(); return; }

    const [_, proxyInfo] = matchingProxy;
    const { target, serviceName } = proxyInfo;
    const requestId = `${request.socket.remoteAddress.replace(/[.:]/g, '-')}_${pathname.replace(/[\/?.]/g, '-')}_${Date.now()}`;
    
    const headers = {
      ...request.headers,
      'x-source': 'gateway',
      'x-target': serviceName,
      'x-request-id': requestId,
      'x-gateway-timestamp': Date.now().toString()
    }

    const options = {
      host: target.host,
      port: target.port,
      path: pathname,
      headers: headers,
      method: 'GET'
    }

    const proxyReq = require('http').request(options);
    proxyReq.on('upgrade', (proxyRes, proxySocket) => {
      socket.write(
        `HTTP/1.1 101 Switching Protocols\r\n` +
        `Upgrade: ${proxyRes.headers.upgrade}\r\n` +
        `Connection: Upgrade\r\n` +
        `Sec-WebSocket-Accept: ${proxyRes.headers['sec-websocket-accept']}\r\n\r\n`
      );

      const connection = {
        id: requestId,
        clientSocket: socket,
        serviceSocket: proxySocket,
        service: serviceName,
        path: pathname,
        clientIp: request.socket.remoteAddress,
        connectedAt: new Date(),
      }

      activeConnections.set(requestId, connection);

      // Connect the client socket with the target socket
      proxySocket.pipe(socket);
      socket.pipe(proxySocket);

      proxySocket.on('error', (_) => { socket.destroy(); if (activeConnections.has(requestId)) activeConnections.delete(requestId); });
      socket.on('error', (_) => { proxySocket.destroy(); if (activeConnections.has(requestId)) activeConnections.delete(requestId); });

      const closeHandler = () => { if (activeConnections.has(requestId)) activeConnections.delete(requestId); }
      proxySocket.on('close', closeHandler);
      socket.on('close', closeHandler);
    });

    proxyReq.on('error', (_) => { socket.destroy(); });
    proxyReq.end();
  });

  // Proxy errors
  fastify.setErrorHandler((error, _, reply) => {
    if (error.code === "ETIMEDOUT") {
      reply.status(408).send({
        statusCode: 408,
        error: "Request Timeout",
        message: "Service took too long to respond",
      });
      return;
    }
    if (error.code === "ECONNREFUSED" || error.code === "ECONNRESET") {
      reply.status(503).send({
        statusCode: 503,
        error: "Service Unavailable",
        message: "Service temporarily unavailable",
      });
      return;
    }
    reply.send(error);
  });

}

module.exports = fp(proxyPlugin, { name: "proxy" });

"use strict";

const fp = require("fastify-plugin");

async function rateLimitPlugin(fastify) {

  const routeRateLimits = [];
  
  // Specific limit for /health
  routeRateLimits.push({
    pattern: "/health",
    method: "GET",
    limit: { max: 20, timeWindow: 10 }
  });

  // Set rate-limit per service
  const services = fastify.config?.services;
    
  if (services) {
    Object.entries(services).forEach(([_, serviceConfig]) => {
      if (serviceConfig && serviceConfig.routes && serviceConfig.prefix) {
        Object.entries(serviceConfig.routes).forEach(([key, route]) => {
          if (route && route.rateLimit) {
            const methods = Array.isArray(route.method) ? route.method : [route.method];
            methods.forEach(method => {
              routeRateLimits.push({
                pattern: `${serviceConfig.prefix}${key}`,
                method: method,
                limit: route.rateLimit
              });
            });
          }
        });
      }
    });
  }

  await fastify.register(require("@fastify/rate-limit"), {
    trustProxy: true,
    global: true,
    max: 100,
    timeWindow: 60 * 1000,

    addHeaders: {
      "x-ratelimit-limit": true,
      "x-ratelimit-remaining": true,
      "x-ratelimit-reset": true,
      "retry-after": true,
    },

    keyGenerator: (req) => `${req.ip}:${req.url}`,

    // Max requests per request
    max: (req, _) => {
      for (const route of routeRateLimits) {
        if (
          (route.method === "*" || route.method === req.method) &&
          req.url.startsWith(route.pattern)
        )
          return route.limit.max;
      }
      return 100;
    },

    // Time window per request
    timeWindow: async (req, _) => {
      for (const route of routeRateLimits) {
        if ((route.method === "*" || route.method === req.method) && req.url.startsWith(route.pattern)) return route.limit.timeWindow * 1000;
      }
      return 60 * 1000;
    },

    // Rate limit exceeded
    errorResponseBuilder: (req, context) => {
      let message = `Too many requests. Please try again in ${context.after} seconds.`;

      for (const route of routeRateLimits) {
        if ((route.method === "*" || route.method === req.method) && req.url.startsWith(route.pattern)) {
          message = `Rate limit exceeded for ${route.pattern}. Please try again in ${context.after} seconds.`;
          break;
        }
      }

      return { statusCode: 429, message: message }
    },
  });

}

module.exports = fp(rateLimitPlugin, { name: "rate-limit" });

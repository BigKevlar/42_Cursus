"use strict";

async function healthRoutes(fastify, options) {
  fastify.get("/health", async (request, reply) => {
      const serviceStatus = {
        service: {
          name: "tournament",
          status: "up",
          uptime: process.uptime(),
          timestamp: new Date().toISOString(),
          version: "1.0",
        },
      };
      return serviceStatus;
    }
  );
}

module.exports = healthRoutes;
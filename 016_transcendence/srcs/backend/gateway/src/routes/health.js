"use strict";

const axios = require("axios");

// Health check
async function healthRoutes(fastify) {

  const services = fastify.config.services;

  fastify.get("/health", async () => {
    const startTime = Date.now();
    const serviceStatus = await checkServices(services, startTime);

    const gatewayStatus = {
      gateway: {
        status: "up",
        uptime: process.uptime(),
        timestamp: new Date().toISOString(),
      },
      services: serviceStatus,
    }
    return gatewayStatus;
  });

}

// Check the status of services
async function checkServices(services, startTime) {
  const serviceStatus = {}

  await Promise.all( Object.entries(services).map(async ([name, config]) => {
    try {
      const { url } = config;
      const response = await axios.get(`${url}/health`, { timeout: 2000, validateStatus: () => true, });
      const responseTime = Date.now() - startTime;
      const status = response.status >= 200 && response.status < 300 ? "up" : "degraded";
      const serv_name = response.data.service.name || name;
      serviceStatus[serv_name] = { status, statusCode: response.status, responseTime: `${responseTime}ms`, }
    } catch (error) {
      serviceStatus[name] = { status: "down", error: error.code || error.message, }
    }
  }));

  return serviceStatus;
}

module.exports = healthRoutes;

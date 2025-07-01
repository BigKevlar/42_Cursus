"use strict";

const fp = require("fastify-plugin");

async function errorHandlerPlugin(fastify) {

  fastify.setNotFoundHandler((request, reply) => {
    reply.code(404).send({
      error: "Resource not found",
      path: request.url,
      method: request.method,
    });
  });

  fastify.setErrorHandler((error, _, reply) => {
    const statusCode = error.statusCode || 500;
    reply.status(statusCode).send({ error: statusCode >= 500 ? "Internal Server Error" : error.message });
  });

}

module.exports = fp(errorHandlerPlugin, { name: "errorHandler" });

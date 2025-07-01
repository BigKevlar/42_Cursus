"use strict";

async function routes(fastify, options) {
  fastify.register(require("./health"));
  fastify.register(require("./oauth"));
  fastify.register(require("./login"));
  fastify.register(require("./signup"));
  fastify.register(require("./refresh"));
  fastify.register(require("./logout"));
  fastify.register(require("./profile"));
}

module.exports = routes;
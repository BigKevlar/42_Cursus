"use strict";

const config = require("./config");
const fastify = require("fastify");
const app = fastify();

app.decorate("config", config);

app.register(require("@fastify/cors"), config.cors);
app.register(require("@fastify/helmet"), config.helmet);
app.register(require('@fastify/jwt'), config.jwt)
app.register(require('@fastify/cookie'), config.cookie)
app.register(require("./plugins/rate-limit"));
app.register(require("./plugins/hooks"));
app.register(require('./plugins/auth'));
app.register(require("./plugins/proxy"));
app.register(require("./plugins/error-handler"));
app.register(require("./routes"));

const shutdown = async () => {
  try {
    await app.close();
    console.log('Server shut down successfully');
    process.exit(0);
  } catch (err) {
    console.error('Server shutdown failure');
    process.exit(1);
  }
}

const start = async () => {
  try {
    await app.ready();
    await app.listen({ port: config.port, host: config.host });
    console.log('Server ready');
    process.on("SIGINT", shutdown);
    process.on("SIGTERM", shutdown);
  } catch (err) {
    console.error('Server failed');
    process.exit(1);
  }
}

start();

"use strict";

let JWTSecret = process.env.JWT_SECRET;
if (!JWTSecret) {
  console.error('[ERROR] JWT_SECRET is required');
  process.exit(1);
}

const config = {
  // Server
  serviceName: (process.env.SERVICE_URL && process.env.SERVICE_URL.split(":")[0]) || "auth",
  port: (process.env.SERVICE_URL && process.env.SERVICE_URL.split(":")[1]) || 4000,
  host: "0.0.0.0", version: "1.0",

  // SQLite
  database: {
    path: "./data/stats.sqlite",
    operationTimeout: 5000,
  },

  // JWT & Cookies
  jwt: {
    secret: JWTSecret,
    expiresIn: process.env.JWT_EXPIRES_IN || '60m',
    refreshExpiresIn: process.env.JWT_REFRESH_EXPIRES_IN || '7d'
  },
  cookie: {
    secret: process.env.COOKIE_SECRET || process.env.JWT_SECRET,
  },
};

module.exports = config;

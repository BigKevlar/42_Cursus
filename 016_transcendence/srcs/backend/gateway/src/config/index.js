"use strict";

const services = require("./services");

let JWTSecret = process.env.JWT_SECRET;
if (!JWTSecret) {
  console.error('[ERROR] JWT_SECRET is required');
  process.exit(1);
}

const config = {

  // Server
  serviceName: (process.env.SERVICE_URL && process.env.SERVICE_URL.split(":")[0]) || "gateway",
  port: (process.env.SERVICE_URL && process.env.SERVICE_URL.split(":")[1]) || 3000,
  host: "0.0.0.0", version: "1.0",

  // Services
  services: services.services,
  routeMap: services.routeMap,

  // CORS
  cors: {
    origin: process.env.CORS_ORIGIN || true,
    methods: ["GET", "POST", "PUT", "DELETE", "PATCH", "OPTIONS"],
    allowedHeaders: ["Content-Type", "Authorization"],
    credentials: true,
  },

  helmet: {
    // Disable CSP since we are not serving HTML/CSS/JS content directly
    contentSecurityPolicy: false,

    // Disable Frameguard since we are not serving content that can be embedded in iframes
    frameguard: false,

    // Protection against XSS
    xssFilter: true,

    // Prevent MIME sniffing
    noSniff: true,

    // Hide server information
    hidePoweredBy: true,

    // Control referrer policy
    referrerPolicy: {
      policy: "no-referrer",
    },

    // Cross-origin resource policies
    crossOriginResourcePolicy: {
      policy: "same-site",
    },

    // Disable unnecessary policies for API
    crossOriginEmbedderPolicy: false,
    crossOriginOpenerPolicy: false,

    // Add HSTS (even though behind nginx)
    strictTransportSecurity: {
      maxAge: 15552000, // 180 days
      includeSubDomains: true,
      preload: true,
    },

    // Prevent DNS prefetching
    dnsPrefetchControl: {
      allow: false,
    },
  },

  // JWT & Cookies
  jwt: {
    secret: JWTSecret,
    expiresIn: process.env.JWT_EXPIRES_IN || '60m',
    refreshExpiresIn: process.env.JWT_REFRESH_EXPIRES_IN || '7d'
  },
  cookie: {
    secret: process.env.COOKIE_SECRET || process.env.JWT_SECRET,
  }
}

module.exports = config;

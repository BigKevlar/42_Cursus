"use strict";

module.exports = {

  name: "auth",
  url: process.env.AUTH_SERVICE_URL || "http://auth:4000",
  prefix: "/auth",
  routes: {    
    "/google": {
      method: ["GET"],
      path: "/goole",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/callback": {
      method: ["GET"],
      path: "/callback",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/logout": {
      method: ["POST"],
      path: "/logout",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/signup": {
      method: ["POST"],
      path: "/signup",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/refresh": {
      method: ["POST"],
      path: "/refresh",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/login": {
      method: ["POST"],
      path: "/login",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/profile": {
      method: ["GET"],
      path: "/profile",
      rateLimit: { max: 20, timeWindow: 10 }
    },

    "/health": {
      method: ["GET"],
      path: "/health",
      rateLimit: { max: 20, timeWindow: 10 }
    },
  },
  timeout: 5000,
}

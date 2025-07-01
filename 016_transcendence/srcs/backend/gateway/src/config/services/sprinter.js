"use strict";

module.exports = {

  name: "sprinter",
  url: process.env.SPRINTER_SERVICE_URL || "http://sprinter:8080",
  prefix: "/sprinter",
  routes: {    
    "/move": {
      method: ["POST"],
      path: "/move",
      rateLimit: { max: 20, timeWindow: 5 }
    },

    "/health": {
      method: ["GET"],
      path: "/health",
      rateLimit: { max: 20, timeWindow: 10 }
    },
  },
  timeout: 5000,
  wsEnabled: true,
  wsPath: "/sprinter",

}
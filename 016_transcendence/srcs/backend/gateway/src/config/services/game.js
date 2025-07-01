"use strict";

module.exports = {

  name: "game",
  url: process.env.GAME_SERVICE_URL || "http://game:8080",
  prefix: "/game",
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
  wsPath: "/game",

}
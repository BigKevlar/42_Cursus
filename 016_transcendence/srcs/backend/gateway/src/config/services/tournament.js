"use strict";

module.exports = {

  name: "tournament",
  url: process.env.TOURNAMENT_SERVICE_URL || "http://tournament:8080",
  prefix: "/tournament",
  routes: {    
    "/create": {
      method: ["POST"],
      path: "/create",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/setresult": {
      method: ["POST"],
      path: "/setresult",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/gettournament": {
      method: ["POST"],
      path: "/gettournament",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    "/deletetournament": {
      method: ["DELETE"],
      path: "/deletetournament",
      rateLimit: { max: 20, timeWindow: 5 }
    },
    
    "/health": {
      method: ["GET"],
      path: "/health",
      rateLimit: { max: 20, timeWindow: 10 }
    },
  },
  timeout: 5000,
}

'use strict'

const fp = require('fastify-plugin')

async function authPlugin(fastify, options) {  
  fastify.decorateRequest('auth', null)
  fastify.addHook('onRequest', async (request, reply) => {
    const publicRoutes = [
      '/auth/login',
      '/auth/signup',
      '/auth/refresh',
      '/auth/google',
      '/auth/callback',
      '/auth/logout',  
      '/health',
      '/auth/health',
      '/game/health',
      '/tournament/health',
      '/sprinter/health',
    ]
    
    request.auth = { authenticated: false }
    if (publicRoutes.some(route => request.url.startsWith(route))) return
    
    let token = null   
    if (request.cookies && request.cookies.authToken) token = request.cookies.authToken
      
    if (!token) {
      return reply.code(401).send({
        statusCode: 401,
        error: 'Unauthorized',
        message: 'Authentication token is required'
      })
    }
      
    try {     
      const decoded = await fastify.jwt.verify(token)
      
      request.auth = {
        authenticated: true,
        id: decoded.sub,
        username: decoded.username
      }     
    } catch (err) {
      let errorType = 'unknown'
      
      if      (err.code === 'FAST_JWT_EXPIRED')           { errorType = 'expired_token' }
      else if (err.code === 'FAST_JWT_MALFORMED')         { errorType = 'malformed_token' }
      else if (err.code === 'FAST_JWT_INVALID_SIGNATURE') { errorType = 'invalid_signature' }
      
      if (err.code === 'FAST_JWT_EXPIRED') {
        return reply.code(401).send({
          statusCode: 401,
          error: 'Unauthorized',
          message: 'Token has expired'
        })
      } else {
        return reply.code(401).send({
          statusCode: 401,
          error: 'Unauthorized',
          type: errorType,
          message: `Invalid authentication token: ${err.message}`
        })
      }
    }
  })
}

module.exports = fp(authPlugin, { name: 'auth', dependencies: ['@fastify/jwt', '@fastify/cookie'] })

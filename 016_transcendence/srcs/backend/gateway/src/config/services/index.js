'use strict'

const serviceAuth = require('./auth')
const serviceGame = require('./game')
const serviceTournament = require('./tournament')
const serviceSprinter = require('./sprinter')

const buildServicesConfig = () => {

  const services = {
    [serviceAuth.name]: serviceAuth,
    [serviceGame.name]: serviceGame,
    [serviceTournament.name]: serviceTournament,
    [serviceSprinter.name]: serviceSprinter,
  }
  
  const routeMap = {}
  
  Object.values(services).forEach(service => {
    if (service.prefix) { routeMap[service.prefix] = service.name }
  })
  
  return { services, routeMap }

}

const { services, routeMap } = buildServicesConfig()

module.exports = { services, routeMap }

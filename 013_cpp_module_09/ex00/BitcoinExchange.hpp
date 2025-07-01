/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:12:12 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/05 13:20:34 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream> 
#include <string>
#include <map>          // 'std::map' lo usaremos para los contenedores.
#include <fstream>      // 'std::ifstream' lo usaremos para leer archivos completos.
#include <sstream>      // 'std::istringstream' lo usaremos para procesar lineas de archivos abiertos.
#include <ctime>        // lo usaremos para almacenar la fecha de los valores leidos.
#include <algorithm>    // 'std::remove_if'
#include <climits>      // 'INT_MAX'
#include <iomanip>      // 'std::fixed' y 'std::setprecision'

class BitcoinExchange
{
    /* Alias para el container (simple ahorro gramatical para el .hpp y .cpp). */
    typedef std::map<std::string, double> container;
    /* Atributos privados. */
    private:
        container _storage;
    /* Atributos publicos. */
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &src);

        void setter(std::string &date, double &value);
        void readDataBase(void);
        double compare(std::string date, double value);
        int chech1stLine(std::string date);
        int parseDate(std::string &date);
        int parseValue(double &date);
        void checkInput(std::string input);        
};
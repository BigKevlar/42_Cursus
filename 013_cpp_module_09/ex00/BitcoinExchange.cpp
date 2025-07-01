/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:12:17 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/11 17:33:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : _storage()
{
    std::cout << "[ Default constructor called! ]" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    std::cout << "[ Destructor called! ]" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _storage(copy._storage)
{
    std::cout << "[ Copy constructor called! ]" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    std::cout << "[ Overload assignation operator called! ]" << std::endl;
    if (this != &src) {
        this->_storage = src._storage;
    }
    else {
        std::cout << "[ Same info. Copy abort! ]" << std::endl;
    }
    return (*this);
}

void BitcoinExchange::setter(std::string &date, double &value)
{
    _storage[date] = value;
}

void BitcoinExchange::readDataBase(void)
{
    std::ifstream csv;
    csv.open("data.csv");
    if (!csv)
    {
        std::cout << "Error: there's no file to open." << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    double value;
    while (std::getline(csv, line))                 // Leemos el archivo usando 'getline' y almacenamos el contenido en 'line'.
    {
        std::istringstream new_line(line);          // Creamos un nuevo objeto tipo 'istringstream' a partir de cada linea leida. Con este objeto podremos extraer datos de los valores de la linea leida.
        if (std::getline(new_line, date, ','))      // Si la condicion de usar 'getline' para leer desde 'new_line' y almacenar en 'date' usando la pipe como delimitador es OK... 
        {
            new_line >> value;                      // ... entonces leemos el valor de 'new_line' y lo almacenamos en 'value'.
            setter(date, value);                    // Por ultimo usamos el 'setter' y almacenamos los valores en el contenedor '_storage' de la parte privada de la clase.
        }
        //std::cout << std::fixed << std::setprecision(2) << date << " | " << value << std::endl;    // DEBUG!!!
    }
}

double BitcoinExchange::compare(std::string date, double value)
{
    for (container::iterator it = _storage.begin(); it != _storage.end(); it++)
    {
        if (it->first == date)
        {
            return (it->second * value);
        }
        else if (it->first > date)
        {
            if (it->first == _storage.begin()->first)
                return (-1);
            it--;
            return (it->second * value);
        }
    }
    return (-1);
}

int BitcoinExchange::chech1stLine(std::string date)
{
    if (date == "date ")
        return 1;
    return 0;
}

int isLeapYear(int year, int month, int day)
{
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if (day > 31 || day <= 0)
				return 1;
			break ;
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (day > 30 || day <= 0)
				return 1;
			break ;
		}
		case 2:
		{
			if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			{
				if (day > 29 || day <= 0)
					return 1;
			}
			else
			{
				if (day > 28 || day <= 0)
					return 1;
			}
			break ;
		}
		default:
			return 1;
	}
	return 0;
}

int BitcoinExchange::parseDate(std::string &date)
{
    date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
    int i = date.find("-", 0);
    int j = date.find("-", i + 1);
    int year = atoi(date.substr(0, i).c_str());
    int month = atoi(date.substr(i + 1, j).c_str());
    int day = atoi(date.substr(j + 1, date.size()).c_str());
    // Fecha mas pequeña: 2009-01-02
    // Fecha mas grande: 2022-03-29
    // Error: bad input => 2001-42-42
	if (year < 2009) {
        std::cout << "Error: bad input" << " => " << date << std::endl;
        return 1;
    }
	if (month < 1 || month > 12) {
        std::cout << "Error: bad input" << " => " << date << std::endl;
        return 1;
    }
	if (isLeapYear(year, month, day)){
        std::cout << "Error: bad input" << " => " << date << std::endl;
        return 1;
    }
    if (year == 2009 && month == 1 && day == 1) {
        std::cout << "Error: bad input" << " => " << date << std::endl;
        return 1;
    }
    return 0;
}

int BitcoinExchange::parseValue(double &value)
{
    if (value <= 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return 1;
    }
    if (value >= 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return 1;
    }
    return 0;
}

void BitcoinExchange::checkInput(std::string input)
{
    readDataBase();
    std::ifstream file;
    file.open(input.c_str());
    if (!file) {
        std::cout << "Error: there's no file to open." << std::endl;
        return ;
    }
    std::string line;
    std::string date;
    double value;
    while(std::getline(file, line))
    {
        int invalid = 0;
        std::istringstream new_line(line);
        if (std::getline(new_line, date, '|'))
        {
            size_t i;
            std::string tmp;
            new_line >> tmp;
            if (chech1stLine(date))
                continue ;
            if (!new_line.eof())
            {
                std::cout << "Error: invalid value." << std::endl;
                continue ;
            }
            for (i = 0; i < tmp.size(); i++) {
                if (!isspace(tmp[i])) break;
            }
            if (tmp[i] == '+' || tmp[i] == '-') i++;
            for (; i < tmp.size(); i++) {
                if (!isdigit(tmp[i]) && tmp[i] != '.') {
                    std::cout << "Error: invalid value." << std::endl;
                    invalid = 1;
                    break ;
                }
            }
            if (invalid == 1)
                continue ;
            std::istringstream tmp_c(tmp);
            tmp_c >> value;
            if (parseDate(date))
                continue ;
            if (parseValue(value))
                continue ;
            double result = compare(date, value);
            // ej.: 2011-01-03 => 3 = 0.9
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
    }
}

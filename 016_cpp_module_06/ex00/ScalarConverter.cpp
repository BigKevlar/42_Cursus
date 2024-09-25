/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:43:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/25 20:31:31 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _inputC(NULL), _inputCPP(NULL), _imposible(false), _value(NULL)
{
	std::cout << "[ Default constructor called! ]" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "[ Destructor called! ]" << std::endl;
}

ScalarConverter::ScalarConverter(char* inputC_) : _inputC(inputC_), _inputCPP(NULL), _imposible(false), _value(NULL)
{
	std::cout << "[ Constructor called! ]" << std::endl;
    _inputCPP = static_cast<std::string>(_inputC);

	try
	{
		_value = std::stod(_inputCPP);
	}
	catch(...)
	{
		_imposible = true;
	}
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy_) : _inputC(copy_._inputC), _inputCPP(copy_._inputCPP), _imposible(copy_._imposible), _value(copy_._value)
{
	std::cout << "[ Copy constructor called! ]" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ Coping... ]" << std::endl;
		_inputC = copy_._inputC;
		_inputCPP = copy_._inputCPP;
		_imposible = copy_._imposible;
		_value = copy_._value;
		return (*this);
	}
	else
	{
		std::cout << "[ Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

void	ScalarConverter::convertionChar(void)
{
	std::cout << "char: ";
	if (_imposible == true)
		std::cout << "impossible";
	else if (isprint(_value) == false)
		std::cout << "non displayable";
	else
		std::cout << static_cast<char>(_value);
	std::cout << std::endl;
}

void	ScalarConverter::convertionInt(void)
{
	std::cout << "int: ";
	if (_imposible = true || isnan(_value))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(_value);
	std::cout << std::endl;
}

void	ScalarConverter::convertionFloat(void)
{
	std::cout << "float: ";
	if (_imposible == true || isnan(_value))
		std::cout << "nanf";
	else
		std::cout << static_cast<float>(_value) << 'f';
	std::cout << std::endl;
}

void	ScalarConverter::convertionDouble(void)
{
	std::cout << "double: ";
	if (_imposible == true || isnan(_value))
		std::cout << "nan";
	else
		std::cout << static_cast<double>(_value);
	std::cout << std::endl;
}

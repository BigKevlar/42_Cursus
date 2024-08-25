/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:25:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/25 21:28:06 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

/* Constructor por defecto, que toma el numero de punto fijo privado y lo inicializa a 0. */
Fixed::Fixed(): _fixed_point_number(0)
{
	std::cout << "[ Default constructor called ]" << std::endl;
}

/* Constructor que crea una copia de un objeto Fixed y asigna "cpy" a este mismo. */
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "[ Copy constructor called ]" << std::endl;
	*this = copy;
}

/* Constructor que recibe un numero int y lo convierte en uno de punto fijo. */
Fixed::Fixed(const int int_number)
{
	std::cout << "[ Int_Number constructor called ]" << std::endl;
	this->_fixed_point_number = int_number << _bits;
}

/* Constructor que recibe un numero float y lo convierte en uno de punto fijo. */
Fixed::Fixed(const float float_number)
{
	std::cout << "[ Float_Number constructor called ]" << std::endl;
	this->_fixed_point_number = roundf(float_number * (1 << Fixed::_bits));
}

/* Destructor por defecto. */
Fixed::~Fixed()
{
		std::cout << "[ Destructor called ]" << std::endl;
}

/* Operador de asignacion. */
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "[ Copy assignment operator called ]" << std::endl;
	this->_fixed_point_number = copy.getRawBits();
	return (*this);
}

/* Getter. */
int	Fixed::getRawBits(void) const
{
	std::cout << "[ getRawBits member function called ]" << std::endl;
	return (this->_fixed_point_number);
}

/* Setter. */
void	Fixed::setRawBits(const int raw)
{
	std::cout << "[ setRawBits member function called ]" << std::endl;
	this->_fixed_point_number = raw;
}

/* Funcion de conversion de numero de punto fijo a float. */
float Fixed::toFloat(void) const
{
	return ((float)(this->_fixed_point_number / (float)(1 << _bits)));
}

/* Funcion de conversion de numero de punto fijo a int. */
int Fixed::toInt(void) const
{
	return (this->_fixed_point_number >> _bits);
}

/* Sobrecarga del operador << para la clase std::ostream: */
std::ostream	&operator<<(std::ostream &output_stream, const Fixed &_fixed_point_number)
{
	output_stream << _fixed_point_number.toFloat();
	return (output_stream);
}

/* Sobrecarga de los operadores de comparacion. */
bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

/* Sobrecarga de los operadores aritmeticos. */
Fixed	Fixed::operator+(Fixed const &copy)
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy)
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy)
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy)
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

//* Sobrecarga de operadores de postincremento y postdecremento. */
Fixed	Fixed::operator++(int number)
{
	Fixed	aux;

	aux = *this;
	if (!number)
		number = 1;
	this->setRawBits(this->getRawBits() + number);
	return (aux);
}

Fixed	Fixed::operator--(int number)
{
	Fixed	aux;

	aux = *this;
	if (!number)
		number = 1;
	this->setRawBits(this->getRawBits() - number);
	return (aux);
}

//* Sobrecarga de operadores de preincremento y predecremento. */
Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

const Fixed	&Fixed::min(const Fixed &copy1, const Fixed &copy2)
{
	if (copy1 < copy2)
		return (copy1);
	return (copy2);
}

const Fixed	&Fixed::max(const Fixed &copy1, const Fixed &copy2)
{
	if (copy1 > copy2)
		return (copy1);
	return (copy2);
}
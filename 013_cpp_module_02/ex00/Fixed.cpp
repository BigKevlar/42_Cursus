/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:25:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/26 13:31:03 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Variable estatica para representar cuantos bits dew aproximacion se van a usar. */
const int	Fixed::_bits = 8;

/* Constructor por defecto: toma el numero de punto fijo privado y lo inicializa a 0. */
Fixed::Fixed(): _fixed_point_number(0)
{
	std::cout << "[ Default constructor called ]" << std::endl;
}

/* Constructor de copia: crea una clase objeto "cpy" y lo copia a este mismo. */
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "[ Copy constructor called ]" << std::endl;
	*this = copy;
}

/* Destructor por defecto. */
Fixed::~Fixed()
{
		std::cout << "[ Destructor called ]" << std::endl;
}

/* Sobrecarga del perador de asignacion. */
Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "[ Copy assignment operator called ]" << std::endl;
	this->_fixed_point_number = copy.getRawBits();
	return *this;
}

/* Getter: tomamos el valor de la clase privada. */
int	Fixed::getRawBits(void) const
{
	std::cout << "[ getRawBits member function called ]" << std::endl;
	return (this->_fixed_point_number);
}

/* Setter: modificamos el valor de la clase privada. */
void	Fixed::setRawBits(const int raw)
{
	std::cout << "[ setRawBits member function called ]" << std::endl;
	this->_fixed_point_number = raw;
}

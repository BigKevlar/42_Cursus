/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:25:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/25 18:45:16 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(): _fixed_point_number(0)
{
	std::cout << "[ Default constructor called ]" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "[ Copy constructor called ]" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int int_number)
{
	std::cout << "[ Int_Number constructor called ]" << std::endl;
	this->_fixed_point_number = int_number << _bits;
}

Fixed::Fixed(const float float_number)
{
	std::cout << "[ Float_Number constructor called ]" << std::endl;
	this->_fixed_point_number = float_number;
	this->_fixed_point_number = roundf(float_number * (1 << Fixed::_bits));
}

Fixed::~Fixed()
{
		std::cout << "[ Destructor called ]" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << "[ Copy assignment operator called ]" << std::endl;
	this->_fixed_point_number = copy.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "[ getRawBits member function called ]" << std::endl;
	return (this->_fixed_point_number);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "[ setRawBits member function called ]" << std::endl;
	this->_fixed_point_number = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)(this->_fixed_point_number / (float)(1 << _bits)));
}

int Fixed::toInt(void) const
{
	return (this->_fixed_point_number >> _bits);
}

std::ostream	&operator<<(std::ostream &output_stream, const Fixed &_fixed_point_number)
{
	output_stream << _fixed_point_number.toFloat();
	return (output_stream);
}

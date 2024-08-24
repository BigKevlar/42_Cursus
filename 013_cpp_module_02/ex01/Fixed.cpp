/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:25:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 19:27:21 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed() : _fixed_point_number(0)
{
	std::cout << "[ Default constructor called ]" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "[ Copy constructor called ]" << std::endl;
	*this = copy;
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
	this->_fixed_point_number = raw;
}
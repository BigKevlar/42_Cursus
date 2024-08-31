/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:13:41 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:45:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "[ (A) Default constructor called. Animal appeared! ]" << std::endl;
}

Animal::Animal(const Animal &copy_)
{
	std::cout << "[ (A) Copy constructor called. ]" << std::endl;
	*this = copy_;
}

Animal::~Animal()
{
	std::cout << "[ (A) Destructor called. ]" << std::endl;
}

Animal &Animal::operator=(const Animal &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (A) Coping... ]" << std::endl;
		_type = copy_._type;
		return (*this);
	}
	else
	{
		std::cout << "[ (A) They are the same. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::string const	&Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "[ (A) ...unrecognized animal noise... " << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:13:41 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/29 18:27:46 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
	std::cout << "[ (WA) Default constructor called. Random animal appeared! ]" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy_)
{
	std::cout << "[ (WA) Copy constructor called. ]" << std::endl;
	*this = copy_;
}

/* Destructor por defecto. */
WrongAnimal::~WrongAnimal()
{
	std::cout << "[ (WA) Destructor called. ]" << std::endl;
}

/* Sobrecarga del operador de asignacion de copia. */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (WA) Coping... ]" << std::endl;
		_type = copy_._type;
		return (*this);
	}
	else
	{
		std::cout << "[ (WA) They are the same. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::string const	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "[ (WA) ...wrong animal noise... " << std::endl;
}

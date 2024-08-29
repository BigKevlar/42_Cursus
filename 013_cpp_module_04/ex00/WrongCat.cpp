/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:34 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/29 18:27:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "[ (WC) Default constructor called. Random_Dog appeared! ]" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy_): WrongAnimal(copy_)
{
	std::cout << "[ (WC) Copy constructor called. ]" << std::endl;
}

/* Destructor por defecto. */
WrongCat::~WrongCat()
{
	std::cout << "[ (WC) Destructor called. ]" << std::endl;
}

/* Sobrecarga del operador de asignacion de copia. */
WrongCat &WrongCat::operator=(const WrongCat &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (WC) Coping... ]" << std::endl;
		_type = copy_._type;
		return (*this);
	}
	else
	{
		std::cout << "[ (WC) They are the same. Copy abort! ]" << std::endl;
		return (*this);
	}
}

void	WrongCat::makeSound(void) const
{
	std::cout << "[ (WC) The animal " << _type << " says... MIAAAGRAAAUUUU! " << std::endl;
}

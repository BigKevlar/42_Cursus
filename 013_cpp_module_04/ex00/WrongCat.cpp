/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:34 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 13:59:05 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "[ (WC) Default constructor called. Wrong_Cat appeared! ]" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy_): WrongAnimal(copy_)
{
	std::cout << "[ (WC) Copy constructor called. ]" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[ (WC) Destructor called. ]" << std::endl;
}

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
	std::cout << "[ (WC) " << "... MIAAAGRAAAUUUU! It's a " << _type << ". ]" << std::endl;
}

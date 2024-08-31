/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:34 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:45:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "[ (D) Default constructor called. Dog appeared! ]" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &copy_): Animal(copy_)
{
	std::cout << "[ (D) Copy constructor called. ]" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[ (D) Destructor called. ]" << std::endl;
}

const	Dog &Dog::operator=(const Dog &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (D) Coping... ]" << std::endl;
		_type = copy_._type;
		return (*this);
	}
	else
	{
		std::cout << "[ (D) They are the same. Copy abort! ]" << std::endl;
		return (*this);
	}
}

void	Dog::makeSound(void) const
{
	Animal::makeSound();
	std::cout << "[ (D) " << "... GUAU GUAU! It's a " << _type << ". ]" << std::endl;
}

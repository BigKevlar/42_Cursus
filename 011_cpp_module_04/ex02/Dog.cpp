/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:34 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 17:24:23 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): AAnimal()
{
	std::cout << "[ (D) Default constructor called. Dog appeared! ]" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog &copy_): AAnimal(copy_)
{
	std::cout << "[ (D) Copy constructor called. ]" << std::endl;
	_type = copy_._type;
	_brain = new Brain(copy_.getBrain());
}

Dog::~Dog()
{
	std::cout << "[ (D) Destructor called. Brain delete too. ]" << std::endl;
	delete (_brain);
}

Dog &Dog::operator=(const AAnimal &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (D) Coping... ]" << std::endl;
		_type = copy_.getType();
		*_brain = copy_.getBrain(); 
	}
	else
	{
		std::cout << "[ (D) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

Dog &Dog::operator=(const Dog &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (D) Coping... ]" << std::endl;
		_type = copy_._type;
		*_brain = copy_.getBrain();
	}
	else
	{
		std::cout << "[ (D) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "[ (D) The animal " << _type << " says... GUAU GUAU! " << std::endl;
}

Brain	&Dog::getBrain(void) const
{
	return (*this->_brain);
}

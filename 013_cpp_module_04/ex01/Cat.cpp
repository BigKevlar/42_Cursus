/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:34 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 17:10:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "[ (C) Default constructor called. Cat appeared! ]" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat &copy_): Animal(copy_)
{
	std::cout << "[ (C) Copy constructor called. ]" << std::endl;
	_type = copy_._type;
	_brain = new Brain(copy_.getBrain());
}

Cat::~Cat()
{
	std::cout << "[ (C) Destructor called. Brain delete too. ]" << std::endl;
	delete (_brain);
}

Cat &Cat::operator=(const Cat &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (C) Coping... ]" << std::endl;
		_type = copy_._type;
		return (*this);
	}
	else
	{
		std::cout << "[ (C) They are the same. Copy abort! ]" << std::endl;
		return (*this);
	}
}

void	Cat::makeSound(void) const
{
	std::cout << "[ (C) The animal " << _type << " says... MIAAAUUUU! " << std::endl;
}

Brain	&Cat::getBrain(void) const
{
	return (*this->_brain);
}

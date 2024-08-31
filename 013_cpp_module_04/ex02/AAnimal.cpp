/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:13:41 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:51:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("AAnimal")
{
	std::cout << "[ (AA) Default constructor called. AAnimal appeared! ]" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy_)
{
	std::cout << "[ (AA) Copy constructor called. ]" << std::endl;
	*this = copy_;
}

AAnimal::~AAnimal()
{
	std::cout << "[ (AA) Destructor called. ]" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (AA) Coping... ]" << std::endl;
		_type = copy_._type;
	}
	else
	{
		std::cout << "[ (AA) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

std::string const	&AAnimal::getType(void) const
{
	return (this->_type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:33:35 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/01 17:52:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "[ (I) Default constructor called. Materia " << _type << " created! ]" << std::endl;
}

Ice::Ice(const Ice &copy_): AMateria("ice")
{
	std::cout << "[ (I) Constructor called. ]" << std::endl;
	*this = copy_;
}

Ice::~Ice()
{
	std::cout << "[ (I) Destructor called. ]" << std::endl;
}

const Ice &Ice::operator=(const Ice &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (I) Coping... ]" << std::endl;
		_type = copy_._type;
	}
	else
	{
		std::cout << "[ (I) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

AMateria	*Ice::clone(void) const
{
    return (new Ice());
}

void		Ice::use(ICharacter &target_)
{
    std::cout << "* shoots an ice bolt at " << target_.getName() << std::endl;
}

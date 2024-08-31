/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:33:35 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 22:25:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria()
{
	std::cout << "[ (C) Default constructor called. " << _type << " created! ]" << std::endl;
}

Cure::Cure(const Cure &copy_): AMateria("cure")
{
	std::cout << "[ (C) Constructor called. ]" << std::endl;
	*this = copy_;
}

Cure::~Cure()
{
	std::cout << "[ (C) Destructor called. ]" << std::endl;
}

const Cure &Cure::operator=(const Cure &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (C) Coping... ]" << std::endl;
		_type = copy_._type;
	}
	else
	{
		std::cout << "[ (C) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

AMateria	*Cure::clone(void) const
{
    return (new Cure());
}

void		Cure::use(ICharacter &target_)
{
    std::cout << "* shoots an ice bolt at " << target_.getName() << std::endl;
}

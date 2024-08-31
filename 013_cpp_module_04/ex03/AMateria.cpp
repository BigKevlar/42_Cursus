/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:08:58 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 22:32:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(): _type()
{
	std::cout << "[ (AM) Default constructor called. New materia created! ]" << std::endl;
}

AMateria::AMateria(const AMateria &copy_)
{
	std::cout << "[ (AM) Constructor called. ]" << std::endl;
	*this = copy_;
}

AMateria::~AMateria()
{
	std::cout << "[ (AM) Destructor called. ]" << std::endl;
}

const AMateria &AMateria::operator=(const AMateria &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (AM) Coping... ]" << std::endl;
		_type = copy_._type;
	}
	else
	{
		std::cout << "[ (AM) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
	std::cout << "[ (AM) Default constructor called. Materia " << _type << " created! ]" << std::endl;
}

const std::string	&AMateria::getType(void) const
{
	return (this->_type);
}

void		AMateria::use(ICharacter &target)
{
	(void) &target;
}

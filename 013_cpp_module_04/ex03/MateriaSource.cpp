/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:26:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 22:08:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _type()
{
	std::cout << "[ (C) Default constructor called. A Materia was created! ]" << std::endl;
}

MateriaSource::MateriaSource(std::string type_) : _type(type_)
{
	std::cout << "[ (C) Default constructor called. Materia " << _type << " created! ]" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy_)
{
	std::cout << "[ (C) Constructor called. ]" << std::endl;
	*this = copy_;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[ (C) Destructor called. ]" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy_)
{
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete (_materia[i]);
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

void MateriaSource::learnMateria(AMateria *m)
{
	if (_materia[0] != NULL)
		*_materia[0] = *m;
	else if (_materia[1] != NULL)
		*_materia[1] = *m;
	else if (_materia[2] != NULL)
		*_materia[2] = *m;
	else if (_materia[3] != NULL)
		*_materia[3] = *m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
		for (int i = 0; i < 4; i++)
		{
			if (_materia[i] && _materia[i]->getType() == type)
				return (_materia[i]->clone());
		}
		return (0);		
}

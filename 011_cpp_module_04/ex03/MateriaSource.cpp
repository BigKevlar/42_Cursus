/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:26:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/01 18:38:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): _materia()
{
	std::cout << "[ (C) Default constructor called. A new materia was created! ]" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy_)
{
	std::cout << "[ (C) Constructor called. ]" << std::endl;
	*this = copy_;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[ (C) Destructor called. ]" << std::endl;
	for (int i = 0; i < 4; i++)
			delete (_materia[i]);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy_)
{
	for (int i = 0; i < 4; i++)
		if (_materia[i])
			delete (_materia[i]);
	if (this != &copy_)
	{
		std::cout << "[ (C) Coping... ]" << std::endl;
		for (int i = 0; i < 4; i++)
			_materia[i] = copy_._materia[i];
	}
	else
	{
		std::cout << "[ (C) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
	/*
	if (_materia[0] == NULL)
		_materia[0] = m;
	else if (_materia[1] == NULL)
		_materia[1] = m;
	else if (_materia[2] == NULL)
		_materia[2] = m;
	else if (_materia[3] == NULL)
		_materia[3] = m;
		*/
	for (int i = 0; i < 4; i++)
		if (_materia[i] == NULL) { _materia[i] = m; return; }
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

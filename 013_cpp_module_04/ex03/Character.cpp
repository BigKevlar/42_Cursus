/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 19:53:23 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/01 18:39:34 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name()
{
	std::cout << "[ (C) Default constructor called. Unamed_Character appeared! ]" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(std::string name_): _name(name_)
{
	std::cout << "[ (C) Default constructor called. " << _name << " appeared! ]" << std::endl;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const Character &copy_)
{
	std::cout << "[ (C) Constructor called. ]" << std::endl;
	this->_name = copy_._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy_._materia[i])
			this->_materia[i] = copy_._materia[i];
	}
}

Character::~Character()
{
	std::cout << "[ (C) Destructor called. ]" << std::endl;
	for (int i = 0; i < 4; i++)
		delete (_materia[i]);
}

Character &Character::operator=(const Character &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (C) Coping... ]" << std::endl;
		this->_name = copy_._name;
	}
	else
	{
		std::cout << "[ (C) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria	*m)
{
	// if (_materia[0] == NULL)
	// 	_materia[0] = m;
	// else if (_materia[1] == NULL)
	// 	_materia[1] = m;
	// else if (_materia[2] == NULL)
	// 	_materia[2] = m;
	// else if (_materia[3] == NULL)
	// 	_materia[3] = m;
	for (int i = 0; i < 4; i++)
		if (_materia[i] == NULL) { _materia[i] = m; return; }
}

void	Character::unequip(int idx)
{
	_materia[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && _materia[idx])
	{
		_materia[idx]->use(target);
	}
}

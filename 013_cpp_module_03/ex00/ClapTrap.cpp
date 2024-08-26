/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:38:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/26 22:12:31 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* Constructor por defecto: crea un nuevo ClapTrap por defecto e inicializa sus valores. */
ClapTrap::ClapTrap(): _name("DefaultTrap"), _hit_points(10), _energy_points(10), _attack_damage(10)
{
	std::cout << "[ Default constructor called. DefaultTrap appeared! ]" << std::endl;
	
}

/* Constructor para nuevos ClapTrap: crea un nuevo ClapTrap con un nombre personal e inicializa sus valores. */
ClapTrap::ClapTrap(std::string name_): _name(name_), _hit_points(10), _energy_points(10), _attack_damage(10)
{
	std::cout << "[ Constructor called. " << _name << " appeared! ]" << std::endl;
}

/* Constructor de copia: crea una clase objeto "cpy" y lo copia a este mismo. */
ClapTrap::ClapTrap(const ClapTrap &copy_)
{
	std::cout << "[ Copy constructor called. ]" << std::endl;
	*this = copy_;
}

/* Destructor por defecto. */
ClapTrap::~ClapTrap()
{
	std::cout << "[ Destructor called. ]" << std::endl;
}

/* Sobrecarga del operador de asignacion de copia. */
ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	_name = copy._name;
	_hit_points = copy._hit_points;
	_energy_points = copy._energy_points;
	_attack_damage = copy._attack_damage;
	return (*this);
}

/**/
void	ClapTrap::attack(const std::string &target_)
{
	if (_hit_points <= 0)
	{
		std::cout << _name << " can't attack. It's dead... " << std::endl;
		return ;
	}
	if (_energy_points == 0)
	{
		std::cout << _name << " can't move. It's so tired... " << std::endl;
		return ;
	}
	_energy_points -= 1;
	std::cout << _name << " attacks " << target_ << ", causing " << _attack_damage << " of damage!" << std::endl;
}

/**/
void	ClapTrap::takeDamage(unsigned int amount_)
{
	_hit_points -= amount_;
	if (_hit_points < 0)
		_hit_points = 0;
	std::cout << _name << " takes " << amount_ << " points of damage!" << std::endl;
}

/**/
void	ClapTrap::beRepaired(unsigned int amount_)
{
	_energy_points -= 1;
	_hit_points += amount_;
	std::cout << _name << " health has been repaired, recovering " << amount_ << " HP. " << std::endl;
}

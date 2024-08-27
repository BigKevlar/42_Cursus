/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:00:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:11:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* Constructor por defecto: crea un nuevo ScavTrap por defecto e inicializa sus valores. */
ScavTrap::ScavTrap()
{
	std::cout << "[ (ST) ScavTrap default constructor called. ScavTrap appeared! ]" << std::endl;
	_name = "ScavTrap";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

/* Constructor para nuevos ScavTrap: crea un nuevo ScavTrap con un nombre personal e inicializa sus valores. */
ScavTrap::ScavTrap(std::string name_)
{
	std::cout << "[ (ST) ScavTrap constructor called. " << _name << " appeared! ]" << std::endl;
	_name = name_;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

/* Constructor de copia: crea una clase objeto "cpy" y lo copia a este mismo. */
ScavTrap::ScavTrap(const ScavTrap &copy_): ClapTrap(copy_)
{
	std::cout << "[ (ST) ScavTrap copy constructor called. ]" << std::endl;
}

/* Destructor por defecto. */
ScavTrap::~ScavTrap()
{
	std::cout << "[ (ST) ScavTrap destructor called. ]" << std::endl;
}

/* Sobrecarga del operador de asignacion de copia. */
ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hit_points = copy._hit_points;
		_energy_points = copy._energy_points;
		_attack_damage = copy._attack_damage;
	}
	return (*this);
}

/* Funcion de ataque. */
void	ScavTrap::attack(const std::string &target_)
{
	if (_hit_points <= 0)
	{
		std::cout << _name << " (ST) can't attack. It's dead... " << std::endl;
		return ;
	}
	if (_energy_points == 0)
	{
		std::cout << _name << " (ST) can't move. It's so tired... " << std::endl;
		return ;
	}
	_energy_points -= 1;
	std::cout << _name << " (ST) attacks " << target_ << ", causing " << _attack_damage << " of damage!" << std::endl;
}

/* Funcion para ponerse en guardia. */
void	ScavTrap::guardGate()
{
	std::cout << _name << " (ST) is now in Guard Gate mode!" << std::endl;
}

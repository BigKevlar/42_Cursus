/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:42:02 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:58:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* Constructor por defecto: crea un nuevo DiamondTrap por defecto e inicializa sus valores. */
DiamondTrap::DiamondTrap(): ClapTrap("DiamondTrap_clap_name"), ScavTrap("DiamondTrap_clap_name"), FragTrap("DiamondTrap_clap_name")
{
	std::cout << "[ (DT) default constructor called. DiamondTrap appeared! ]" << std::endl;
	_name = "DiamondTrap";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
}

/* Constructor para nuevos DiamondTrap: crea un nuevo DiamondTrap con un nombre personal e inicializa sus valores. */
DiamondTrap::DiamondTrap(std::string name_)
{
	std::cout << "[ (DT) constructor called. " << _name << " appeared! ]" << std::endl;
	_name = name_;
	ClapTrap::_name = _name + "_clap_name";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
}

/* Constructor de copia: crea una clase objeto "cpy" y lo copia a este mismo. */
DiamondTrap::DiamondTrap(const DiamondTrap &copy_): ClapTrap(copy_), ScavTrap(copy_), FragTrap(copy_)
{
	std::cout << "[ (DT) copy constructor called. ]" << std::endl;
}

/* Destructor por defecto. */
DiamondTrap::~DiamondTrap()
{
	std::cout << "[ (DT) destructor called. ]" << std::endl;
}

/* Sobrecarga del operador de asignacion de copia. */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_hit_points = copy._hit_points;
		_energy_points = copy._energy_points;
		_attack_damage = copy._attack_damage;
	}
	FragTrap::operator=(copy);
	return (*this);
}

/* Funcion de ataque. */
void	DiamondTrap::attack(const std::string &target_)
{
	ScavTrap::attack(target_);
	std::cout << "- _hit_points: " << _hit_points << std::endl;
	std::cout << "- _energy_points: " << _energy_points << std::endl;
	std::cout << "- _attack_damage: " << _attack_damage << std::endl;
}

/* Funcion para mostrar los nombres. */
void	DiamondTrap::whoAmI(void)
{
	std::cout << "I'm " << _name << ", but my friends call me " << ClapTrap::_name << std::endl;
}

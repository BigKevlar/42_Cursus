/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 14:00:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:14:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* Constructor por defecto: crea un nuevo FragTrap por defecto e inicializa sus valores. */
FragTrap::FragTrap()
{
	std::cout << "[ (FT) default constructor called. FragTrap appeared! ]" << std::endl;
	_name = "FragTrap";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

/* Constructor para nuevos FragTrap: crea un nuevo FragTrap con un nombre personal e inicializa sus valores. */
FragTrap::FragTrap(std::string name_)
{
	std::cout << "[ (FT) constructor called. " << _name << " appeared! ]" << std::endl;
	_name = name_;
	_hit_points = 100;
	_energy_points = 100;
	_attack_damage = 30;
}

/* Constructor de copia: crea una clase objeto "cpy" y lo copia a este mismo. */
FragTrap::FragTrap(const FragTrap &copy_): ClapTrap(copy_)
{
	std::cout << "[ (FT) copy constructor called. ]" << std::endl;
}

/* Destructor por defecto. */
FragTrap::~FragTrap()
{
	std::cout << "[ (FT) destructor called. ]" << std::endl;
}

/* Sobrecarga del operador de asignacion de copia. */
FragTrap &FragTrap::operator=(const FragTrap &copy)
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

/* Funcion para chocarla. */
void	FragTrap::highFivesGuys()
{
	std::cout << _name << " (FT) up his left hand... GIVE ME FIVE!" << std::endl;
}

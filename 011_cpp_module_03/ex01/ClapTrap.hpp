/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:32:11 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 14:01:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		/* Atributos privados. */
		std::string	_name; // Nombre del ClapTrap.
		int			_hit_points; // Vida.
		int			_energy_points; // Puntos para realizar acciones.
		int			_attack_damage; // Daño por ataque.
	public:
		/* Constructores y destructor. */
		ClapTrap();
		ClapTrap(std::string name_);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();
		/* Operador de copia. */
		ClapTrap &operator=(const ClapTrap &copy);
		/* Funciones de clase. */
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

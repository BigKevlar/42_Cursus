/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:45:17 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:56:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name; // Nombre del DiamondTrap.

		using ScavTrap::_hit_points;
	public:
		/* Constructores y destructor. */
		DiamondTrap();
		DiamondTrap(std::string name_);
		DiamondTrap(const DiamondTrap &copy);
		~DiamondTrap();
		/* Operador de copia. */
		DiamondTrap	&operator=(const DiamondTrap &copy);
		/* Funciones de clase. */
		void	attack(const std::string &target_);
		void	whoAmI(void);
};

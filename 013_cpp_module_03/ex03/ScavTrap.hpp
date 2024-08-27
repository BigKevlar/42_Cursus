/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:45 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 16:59:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	private:
	public:
		/* Constructores y destructor. */
		ScavTrap();
		ScavTrap(std::string name_);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();
		/* Operador de copia. */
		ScavTrap	&operator=(const ScavTrap &copy);
		/* Funciones de clase. */
		void	attack(const std::string &target);
		void	guardGate();
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:57:45 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 16:59:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	private:
	public:
		/* Constructores y destructor. */
		FragTrap();
		FragTrap(std::string name_);
		FragTrap(const FragTrap &copy);
		~FragTrap();
		/* Operador de copia. */
		FragTrap	&operator=(const FragTrap &copy);
		/* Funciones de clase. */
		void	highFivesGuys(void);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:29:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:21:01 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap	Claptrap("ClapSoldier");
	ScavTrap	Scavtrap_1("ScavSoldier_1");
	ScavTrap	Scavtrap_2("ScavSoldier_2");
	FragTrap	Fragtrap("FragSoldier");

	Claptrap.attack("zombie");
	Claptrap.takeDamage(8);
	Claptrap.takeDamage(3);
	Claptrap.beRepaired(30);
	Claptrap.attack("zombie");

	Scavtrap_1.attack("zombie");
	Scavtrap_1.takeDamage(8);
	Scavtrap_1.takeDamage(3);
	Scavtrap_1.beRepaired(30);
	Scavtrap_1.attack("zombie");

	Scavtrap_2.guardGate();
	Scavtrap_2 = Scavtrap_1; 
	Scavtrap_2.guardGate();

	Scavtrap_2 = Scavtrap_2;
	Scavtrap_2.guardGate();

	Fragtrap.attack("zombie");
	Fragtrap.highFivesGuys();
	
	return (0);
}

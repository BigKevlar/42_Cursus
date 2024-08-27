/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:29:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:06:13 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	PJ_0("Soldier_1");
	ScavTrap	PJ_1("Soldier_2");
	ScavTrap	PJ_2("Soldier_3");

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
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:29:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 17:49:35 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	Diamondtrap;

	std::cout << std::endl;
	Diamondtrap.attack("Bob");
	Diamondtrap.attack("Chris");
	Diamondtrap.attack("Diana");
	Diamondtrap.attack("Elisa");
	Diamondtrap.attack("Fred");
	Diamondtrap.attack("Gemma");
	Diamondtrap.attack("Henry");
	Diamondtrap.attack("Isabella");
	Diamondtrap.attack("Jack");
	Diamondtrap.attack("Kevin");
	Diamondtrap.attack("Laura");
	Diamondtrap.attack("Mike");
	std::cout << std::endl;
	Diamondtrap.takeDamage(42);
	Diamondtrap.beRepaired(24);
	std::cout << std::endl;
	Diamondtrap.guardGate();
	Diamondtrap.highFivesGuys();
	Diamondtrap.whoAmI();
	std::cout << std::endl;
	
	return (0);
}

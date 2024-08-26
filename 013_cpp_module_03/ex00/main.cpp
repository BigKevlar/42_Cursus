/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:29:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/26 21:48:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Claptrap("Deadpool");

	Claptrap.attack("Wolverine");
	Claptrap.takeDamage(8);
	Claptrap.takeDamage(3);
	Claptrap.beRepaired(30);
	Claptrap.attack("Wolverine");
	
	return (0);
}

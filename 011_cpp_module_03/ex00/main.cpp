/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:29:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/27 18:05:33 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	PJ("Soldier");

	PJ.attack("zombie");
	PJ.takeDamage(8);
	PJ.beRepaired(30);
	PJ.attack("zombie");
	
	return (0);
}

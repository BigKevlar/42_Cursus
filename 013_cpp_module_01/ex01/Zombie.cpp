/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:52:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 19:22:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
	Constructor...
*/
Zombie::Zombie()
{
	std::cout << "Zombie appeared!" << std::endl;
}

/*
	Destructor...
*/
Zombie::~Zombie()
{
	std::cout << "Zombie died... again." << std::endl;
}

/*
	Aviso de creacion de un nuevo zombie en la orda.
*/
void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

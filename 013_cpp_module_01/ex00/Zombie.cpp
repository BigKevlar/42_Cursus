/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:52:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/14 20:49:44 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
    Constructor...
*/
Zombie::Zombie(std::string name)
{
    this->_name = name;
    std::cout << "Zombie " << this->_name << " appeared!" << std::endl;
}

/*
    Destructor...
*/
Zombie::~Zombie()
{
    std::cout << "Zombie " << this->_name << " died... again." << std::endl;
}

/*
    Aviso de creacion de un nuevo zombie, ya sea random o para qudarse.
*/
void    Zombie::announce()
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

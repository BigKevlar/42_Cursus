/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:56:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/15 16:28:04 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
    std::cout << "Weapon type " << this->_type << " created!" << std::endl;
};

Weapon::~Weapon()
{
    std::cout << "Weapon type " << this->_type << " destroyed!" << std::endl;
};

std::string    Weapon::getType()
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}

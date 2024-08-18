/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:52:13 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/19 00:25:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_type): _name(name), _weapon_type(weapon_type)
{
    this->_name = name;
    std::cout << "HumanA " << this->_name << " appeared!" << std::endl;
    this->_weapon_type = weapon_type.getType();
};

HumanA::~HumanA(){};

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weapon_type.getType() << std::endl;
}

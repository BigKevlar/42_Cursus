/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:47:14 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 19:26:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon_type(NULL)
{
	this->_name = name;
	std::cout << "HumanB " << this->_name << " appeared!" << std::endl;
};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &weapon_type)
{
	this->_weapon_type = &weapon_type;
}

void	HumanB::attack()
{
	if (this->_weapon_type == NULL)
	{
		std::cout << this->_name << " don't have weapon..." << std::endl;
		return;
	}
	else
		std::cout << this->_name << " attacks with their " << this->_weapon_type->getType() << std::endl;
}

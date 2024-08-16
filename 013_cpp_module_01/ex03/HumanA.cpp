/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:52:13 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/16 21:21:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
    std::cout << "HumanA " << this->_name << " appeared!" << std::endl;
    std::cout << "It have " << weapon.getType() << " weapon."  << std::endl;
};

HumanA::~HumanA()
{
    std::cout << "HumanA " << this->_name << " disappeared!" << std::endl;
};


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:56:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/19 00:21:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{};

Weapon::~Weapon()
{};

const std::string    &Weapon::getType()
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}

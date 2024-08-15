/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:52:13 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/15 16:28:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name)
{
    std::cout << "HumanA " << this->_name << " appeared!" << std::endl;
};

HumanA::~HumanA()
{
    std::cout << "HumanA " << this->_name << " disappeared!" << std::endl;
};

std::string    HumanA::getName()
{
    return (this->_name);
}

void    HumanA::setName(std::string name)
{
    this->_name = name;
}

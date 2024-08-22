/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:35:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 20:26:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "\n" << "***Constructor called***" << "\n" << std::endl;
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";
	this->ptr[0] = &Harl::_debug;
	this->ptr[1] = &Harl::_info;
	this->ptr[2] = &Harl::_warning;
	this->ptr[3] = &Harl::_error;
}

Harl::~Harl()
{
	std::cout << "\n" << "***Destructor called***" << "\n" << std::endl;
}

void	Harl::_debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::_info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string _level)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_level[i] == _level)
		{
			(this->*ptr[i])();
			return ;
		}
	}
}

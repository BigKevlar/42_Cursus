/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:35:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 20:47:51 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "\n"
			  << "***Constructor called***" << "\n"
			  << std::endl;
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
	std::cout << "***Destructor called***" << "\n"
			  << std::endl;
}

void	Harl::_debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::_info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::_warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::_error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::filter(std::string level)
{
	int	i;

	for (i = 0; i <= 4; i++)
	{
		if (i == 4)
			break;
		if (this->_level[i] == level)
			break;
	}
	switch (i)
	{
		case 0:
			Harl::_debug();
		case 1:
			Harl::_info();
		case 2:
			Harl::_warning();
		case 3:
			Harl::_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

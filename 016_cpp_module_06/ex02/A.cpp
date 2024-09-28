/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:14:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/28 17:24:13 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
	std::cout << "[ Default constructor called! ]" << std::endl;
}

Base::~Base()
{
	std::cout << "[ Destructor called! ]" << std::endl;
}

Base::Base(const Base &copy_)
{
	std::cout << "[ Copy constructor called! ]" << std::endl;
	*this = copy_;
}

Base &Base::operator=(const Base &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ Coping... ]" << std::endl;
		return (*this);
	}
	else
	{
		std::cout << "[ Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

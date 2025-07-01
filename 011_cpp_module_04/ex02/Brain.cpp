/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:13:41 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:51:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[ (B) Default constructor called. Brain with 100 ideas created! ]" << std::endl;
}

Brain::Brain(const Brain &copy_)
{
	std::cout << "[ (B) Copy constructor called. ]" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas_[i] = copy_.ideas_[i];
	*this = copy_;
}

Brain::~Brain()
{
	std::cout << "[ (B) Destructor called. ]" << std::endl;
}

Brain &Brain::operator=(const Brain &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (B) Coping... ]" << std::endl;
		for (int i = 0; i < 100; i++)
			ideas_[i] = copy_.ideas_[i];
	}
	else
	{
		std::cout << "[ (B) They are the same. Copy abort! ]" << std::endl;
	}
	return (*this);
}

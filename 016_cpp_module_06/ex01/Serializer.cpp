/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:14:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/28 16:11:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "[ Default constructor called! ]" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "[ Destructor called! ]" << std::endl;
}

Serializer::Serializer(const Serializer &copy_)
{
	std::cout << "[ Copy constructor called! ]" << std::endl;
	*this = copy_;
}

Serializer &Serializer::operator=(const Serializer &copy_)
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

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::unserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

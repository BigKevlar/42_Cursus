/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:09:04 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/28 16:14:07 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>	//uintptr_t

typedef struct	Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}				t_Data;

class Serializer
{
	private:
	public:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy_);
		Serializer	&operator=(const Serializer &copy_);
		uintptr_t	serialize(Data *ptr);
		Data		*unserialize(uintptr_t raw);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:09:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/29 20:11:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	public:
		/* Constructores y destructor. */
		Brain();
		Brain(const Brain &copy_);
		virtual	~Brain();
		/* Operador de copia. */
		Brain &operator=(const Brain &copy_);
		/* Atributos publicos. */
		std::string	ideas_[100];
};

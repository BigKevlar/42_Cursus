/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/29 18:44:16 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat: virtual public Animal
{
	public:
		/* Constructores y destructor. */
		Cat();
		Cat(std::string type_);
		Cat(const Cat &copy_);
		~Cat();
		/* Operador de copia. */
		Cat &operator=(const Cat &copy_);
		/* Funciones de clase. */
		void 	makeSound(void) const;
};

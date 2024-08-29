/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/29 20:14:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal
{
	private:
		Brain *_brain;
	public:
		/* Constructores y destructor. */
		Dog();
		Dog(std::string type_);
		Dog(const Dog &copy_);
		~Dog();
		/* Operador de copia. */
		Dog &operator=(const Dog &copy_);
		/* Funciones de clase. */
		void	makeSound(void) const;
		Brain	&getBrain(void) const;
};

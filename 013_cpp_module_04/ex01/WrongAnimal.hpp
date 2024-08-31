/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:09:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:31:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		/* Atributos privados. */
		std::string	_type;
	public:
		/* Constructores y destructor. */
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy_);
		virtual	~WrongAnimal();
		/* Operador de copia. */
		WrongAnimal &operator=(const WrongAnimal &copy_);
		/* Funciones de clase. */
		virtual std::string const	&getType(void) const;
		void 						makeSound(void) const;	// Hemos quitado el virtual, para que lo coja del padre.
													// Asi vemos que al ponerlo como virtual o no
};

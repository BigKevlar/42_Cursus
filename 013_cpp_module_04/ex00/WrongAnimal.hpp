/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:09:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:31:05 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy_);
		virtual	~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &copy_);
		virtual std::string const	&getType(void) const;
		void 						makeSound(void) const;	// Hemos quitado el virtual, para que lo coja del padre.
															// Asi vemos que al ponerlo como virtual o no toma
															// el suyo y no el del padre.
};

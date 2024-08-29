/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/29 18:44:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	protected:
	public:
		/* Constructores y destructor. */
		WrongCat();
		WrongCat(std::string type_);
		WrongCat(const WrongCat &copy_);
		~WrongCat();
		/* Operador de copia. */
		WrongCat &operator=(const WrongCat &copy_);
		/* Funciones de clase. */
		void 				makeSound(void) const;
};

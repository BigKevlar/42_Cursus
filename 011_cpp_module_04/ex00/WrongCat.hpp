/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:34:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 13:59:23 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat: virtual public WrongAnimal
{
	/* El privado lo hereda de WrongAnimal. */
	public:
		WrongCat();
		WrongCat(std::string type_);
		WrongCat(const WrongCat &copy_);
		~WrongCat();
		WrongCat &operator=(const WrongCat &copy_);
		void 				makeSound(void) const;
};

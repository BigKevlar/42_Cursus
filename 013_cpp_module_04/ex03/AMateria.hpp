/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:20:04 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 22:32:02 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(const AMateria &copy_);
		virtual ~AMateria();
		virtual const AMateria &operator=(const AMateria &copy_);
		//
		AMateria(std::string const &type);
		std::string const	&getType(void) const;
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
};

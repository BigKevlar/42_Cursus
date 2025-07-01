/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:19:01 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 22:30:51 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual				~IMateriaSource(){};
		virtual void		learnMateria(AMateria *materia) = 0;
		virtual AMateria	*createMateria(std::string const & type) = 0;
};

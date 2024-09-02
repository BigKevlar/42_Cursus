/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:22:20 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/01 18:18:51 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria	*_materia[4];
	public:
    	MateriaSource();
		MateriaSource(const MateriaSource &copy_);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &copy_);
		//
		void		learnMateria(AMateria *materia);
		AMateria	*createMateria(std::string const &type);
};

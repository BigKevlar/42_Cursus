/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:22:20 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 21:34:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        std::string _type;
        AMateria	*_materia[4];
	public:
    	MateriaSource();
		MateriaSource(std::string name_);
		MateriaSource(const MateriaSource &copy_);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource &copy_);
		//
		void		learnMateria(AMateria *materia);
		AMateria	*createMateria(std::string const &type);
};

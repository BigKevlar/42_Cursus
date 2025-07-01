/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:06 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/16 13:28:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// El archivo .hpp contiene la "declaracion" de las funciones.

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>		// std
#include <algorithm>	// find
#include <vector>		// vector
#include <deque>		// deque

template <typename T>
typename T::iterator easyfind(T &container, int number);

class NotFoundException: public std::exception {
	public:
		virtual char const	*what() const throw();
};

#include "Easyfind.tpp"

#endif
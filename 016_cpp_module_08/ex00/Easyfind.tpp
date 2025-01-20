/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:57:45 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/16 12:27:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// El archivo .tpp contiene la "implementacion" de las funciones.

#include "Easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int number) {
    typename T::iterator ok = std::find(container.begin(), container.end(), number);
    if (ok == container.end())
        throw NotFoundException();
    return ok;
}

char const *NotFoundException::what() const throw() {
	return ("Number not found in the container. Try again!");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:55:45 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 19:21:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	size = 6;

	Zombie	*horde = zombieHorde(size, "Zombie");
	for (int c = 0; c < size; c++)
		horde[c].announce();
	delete[] horde;
	return (0);
}

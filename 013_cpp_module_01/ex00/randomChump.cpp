/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:25:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/15 13:19:34 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
    Crea un zombie que pasaba por ahi...
*/
void    randomChump(std::string name)
{
    Zombie  *randomZombie;
    
    randomZombie = newZombie(name);
    randomZombie->announce();
    delete (randomZombie);
}

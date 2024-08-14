/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:25:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/14 20:26:31 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
    Crea un zombie que pasaba por ahi...
*/
void    randomChump(std::string name)
{
    Zombie  *random_zombie;
    
    random_zombie = newZombie(name);
    random_zombie->announce();
    delete (random_zombie);
}

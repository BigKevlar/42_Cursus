/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:23:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/14 20:24:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
    Crea un zombie para "guardarlo"...
*/
Zombie  *newZombie(std::string name)
{
    Zombie  *new_zombie;
    
    new_zombie = new Zombie(name);
    return (new_zombie);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:55:45 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/14 19:37:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  *Charmander = newZombie("Charmander");;
    Zombie  *Squirtel = newZombie("Squirtel");
    Zombie  *Bulbasur = newZombie("Bulbasur");
    
    Charmander->announce();
    Squirtel->announce();
    Bulbasur->announce();
    randomChump("Pikachu");
    delete(Charmander);
    delete(Squirtel);
    delete(Bulbasur);
    return (0);
}

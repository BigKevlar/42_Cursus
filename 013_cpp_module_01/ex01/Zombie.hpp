/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:10:10 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/14 20:28:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
    
        std::string _name;
        
    public:
    
        Zombie(std::string name);
        ~Zombie();
        void announce();
};

Zombie  *zombieHorde( int N, std::string name );

#endif

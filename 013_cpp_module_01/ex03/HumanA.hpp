/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:31:13 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/15 16:29:52 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      *_weapon;
    public:
        HumanA(std::string _name, Weapon &weapon);
        ~HumanA();
        std::string getName();
        void        setName(std::string name);
        void        setWeapon(std::string weapon);
        void        attack();
};

#endif

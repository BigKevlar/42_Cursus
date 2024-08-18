/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:46:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/19 00:33:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

/*
    A ESTA CLASE LE VAMOS A PASAR EL ARMA POR PUNTERO MEDIANTE EL USO DE
    UN SETTER, Y NO EN EL CONSTRUCTOR.
*/
class HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon_type;
    public:
        HumanB(std::string name);
        ~HumanB();
        void        setWeapon(Weapon &weapon_type);
        void        attack();
};

#endif
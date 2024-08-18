/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:31:13 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/19 00:32:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/*
    A ESTA CLASE LE VAMOS A PASAR EL ARMA POR REFERENCIA Y EN EL CONSTRUCTOR,
    SIN NINGUN TIPO DE SETTER.
*/
class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon_type;
    public:
        HumanA(std::string name, Weapon &weapon_type);
        ~HumanA();
        void        attack();
};

#endif

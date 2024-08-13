/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:22:12 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/13 19:22:13 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
    /* ATRIBUTOS */
    private:
        Contact _contact[8];
        int     _index;
    /* METODOS */
    public:
        /* CONSTRUCTOR ESTANDAR */ 
        Phonebook();
        /* DESTRUCTOR ESTANDAR */
        ~Phonebook();
        /* FUNCIONES DE ACCION DEL PHONEBOOK */
        void    add();
        void    search();
        /* OTRAS */
        void    show_phonebook();
};

#endif
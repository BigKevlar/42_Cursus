/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:06 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/20 11:19:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span {
    private:
        unsigned int _size;                                         // TAMAÑO DEL VECTOR (PONEMOS UNSIGNED INT PARA LA ENTRADA DE N_ EN EL CONSTRUCTOR).
        unsigned int _position;                                     // POSICION ACTUAL DEL ITERADOR (PONEMOS UNSIGNED INT PARA QUE NO DE PROBLEMAS AL COMPARARLO CON SIZE).
        std::vector<int> _storage;                                  // VECTOR DE ALMACENAMIENTO DE NUMEROS.
    public:                 
        Span();                                                     // (OBLIGATORIO) CONSTRUCTOR.
        Span(unsigned int N_);                  
        Span(const Span &src);                                      // (OBLIGATORIO) CONSTRUCTOR DE COPIA.
        ~Span();                                                    // (OBLIGATORIO) DESTRUCTOR.
        Span    &operator=(const Span &src);                        // (OBLIGATORIO) SOBRECARGA DEL OPERADOR DE ASIGNACION.
        void    addNumber(int number_);
        int     shortestSpan();                                     // ESTA FUNCION CALCULA LA DISTANCIA ENTRE LOS DOS NUMEROS MAS CERCANOS.
        int     longestSpan();                                      // ESTA FUNCION CALCULA LA DISTANCIA ENTRE EL NUMERO MAS PEQUEÑO Y EL MAS GRANDE.
        class   StorageFullException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
        class   StorageEmptyException: public std::exception {
            public:
                virtual const char *what() const throw();
        };
};
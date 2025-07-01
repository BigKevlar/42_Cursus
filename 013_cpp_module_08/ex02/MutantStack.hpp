/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:43:26 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/20 14:52:51 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <list>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
    private:
    public:
        /* Alias para usar unicamente 'iterator'*/
        typedef typename std::stack<T>::container_type::iterator iterator;

        /* Metodos obligatorios para la clase canonica ortodoxa */
        MutantStack() {
            std::cout << "[ Default constructor called! ]" << std::endl;
        }
        ~MutantStack() {
            std::cout << "[ Destructor called! ]" << std::endl;
        }
        MutantStack(const MutantStack &src) {
            std::cout << "[ Copy constructor called! ]" << std::endl;
            *this = src;
        };
        MutantStack &operator=(const MutantStack &src) {
            std::cout << "[ Overload assignation operator called! ]" << std::endl;
            if (this != &src) {
                this->c = src.c;
            }
            else {
                std::cout << "[ Same info. Copy abort! ]" << std::endl;
            }
            return (*this);
        };
    
        /* Iteradores */
        iterator begin() {
            return (this->c.begin());
        }
        iterator end() {
            return (this->c.end());
        }
};
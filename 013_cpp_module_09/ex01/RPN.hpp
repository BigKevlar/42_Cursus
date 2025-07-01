/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:55 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/05 16:49:41 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>
#include <cstring>  // 'strlen'.

class RPN
{
    /* Alias para el container (simple ahorro gramatical para el .hpp y .cpp). */
    typedef std::stack<int> container;
    /* Atributos privados. */
    private:
    container _calculator;
    /* Atributos publicos. */
    public:
        RPN();
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &src);
        
        void parseInput(std::string input);
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:13:57 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/17 16:27:59 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    Span numberContainer00 = Span(1);
    Span numberContainer01 = Span(6);
    Span numberContainer02 = Span(10042);
    
    try
    {
        numberContainer00.addNumber(42);
        
        std::cout << "Shortest span 00 is " << numberContainer00.shortestSpan() << std::endl;
        std::cout << "Longest span 00 is " << numberContainer00.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try {
        numberContainer01.addNumber(-5);
        numberContainer01.addNumber(2);
        numberContainer01.addNumber(0);
        numberContainer01.addNumber(6);
        numberContainer01.addNumber(2024);
        numberContainer01.addNumber(42);
        
        std::cout << "Shortest span 01 is " << numberContainer01.shortestSpan() << std::endl;
        std::cout << "Longest span 01 is " << numberContainer01.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        for (int i = 0; i < 10042; i++) {
            numberContainer02.addNumber(i);
        }
        
        std::cout << "Shortest span 02 is " << numberContainer02.shortestSpan() << std::endl;
        std::cout << "Longest span 02 is " << numberContainer02.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
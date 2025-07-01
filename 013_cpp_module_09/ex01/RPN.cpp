/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:12:17 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/11 17:43:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _calculator()
{
    std::cout << "[ Default constructor called! ]" << std::endl;
}

RPN::~RPN()
{
    std::cout << "[ Destructor called! ]" << std::endl;
}

RPN::RPN(const RPN &copy) : _calculator(copy._calculator)
{
    std::cout << "[ Copy constructor called! ]" << std::endl;
}

RPN &RPN::operator=(const RPN &src)
{
    std::cout << "[ Overload assignation operator called! ]" << std::endl;
    if (this != &src) {
        this->_calculator = src._calculator;
    }
    else {
        std::cout << "[ Same info. Copy abort! ]" << std::endl;
    }
    return (*this);
}

void RPN::parseInput(std::string input)
{
    int digits = 0;
    int size = input.size();
    int a;
    int b;
    for (int i = 0; i < size; i++) {
        if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != ' ') {
            std::cout << "ERROR: bad character." << std::endl;
            return ;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (input[i] == ' ')
            continue;
        if (isdigit(input[i])) {
            _calculator.push(input[i] - '0');
            digits++;
        } else if (_calculator.size() < 2) {
            std::cout << "ERROR: not enough numbers." << std::endl;
            return ;
        } else if (i == 0 && (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')) {
            std::cout << "ERROR: bad syntax." << std::endl;
            return ;
        } else if (i > 0 && (input[i - 1] == '+' || input[i - 1] == '-' || input[i - 1] == '*' || input[i - 1] == '/')) {
            std::cout << "ERROR: bad syntax." << std::endl;
            return ;
        } else if (input[i] == '+') {
            a = _calculator.top();
            _calculator.pop();
            b = _calculator.top();
            _calculator.pop();
            _calculator.push(a + b);
            digits--;
        }
        else if (input[i] == '-') {
            a = _calculator.top();
            _calculator.pop();
            b = _calculator.top();
            _calculator.pop();
            _calculator.push(b - a);
            digits--;
        }
        else if (input[i] == '*') {
            a = _calculator.top();
            _calculator.pop();
            b = _calculator.top();
            _calculator.pop();
            _calculator.push(a * b);
            digits--;
        }
        else if (input[i] == '/') {
            a = _calculator.top();
            _calculator.pop();
            b = _calculator.top();
            _calculator.pop();
            if (a == 0) {
                std::cout << "ERROR: division fail." << std::endl;
                return ;
            }
            _calculator.push(b / a);
            digits--;
        }
    }
    if (digits != 1) {
        std::cout << "ERROR: missing operands." << std::endl;
        return ;
    }
    std::cout << _calculator.top() << std::endl;
}
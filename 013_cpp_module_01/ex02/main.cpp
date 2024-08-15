/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:03:38 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/15 14:44:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *brainPointer = &brain;
    std::string &brainReference = brain;

    std::cout << "The memory address of the string variable is: " << &brain << std::endl;
    std::cout << "The memory address held in brainPointer is: " << brainPointer << std::endl;
    std::cout << "The memory address held in  brainReference is: " << &brainReference << std::endl;
    std::cout << std::endl;
    std::cout << "The value of the string variable is: " << brain << std::endl;
    std::cout << "The value pointed to brainPointer is: " << *brainPointer << std::endl;
    std::cout << "The value pointed to brainReference is: " << brainReference << std::endl;
}
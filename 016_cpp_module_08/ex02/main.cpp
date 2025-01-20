/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:45:59 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/20 14:59:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

    Funciones mas usadas en los "stacks":

        - example.push(): Agrega un objeto al final del stack.
        - example.pop(): Elimina el ultimo objeto del stack.
        - example.top(): Devuelve el ultimo objeto del stack.
        - example.size(): Devuelve el tamaño del stack.
        - example.empty(): Devuelve si el stack esta vacio o no.

*/

/* (main copiado del subject y personalizado para mas aclaracion) */
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Size is " << mstack.size() << std::endl;
    std::cout << "The last number in stack is " << mstack.top() << std::endl;
    std::cout << "Deleting the last one!" << std::endl;
    mstack.pop();
    std::cout << "New size is" << mstack.size() << std::endl;
    std::cout << "So now the last and only is " << mstack.top() << std::endl;
    
    std::cout << "Now we insert new numbers!" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator itStart = mstack.begin();
    MutantStack<int>::iterator itEnd = mstack.end();
    
    std::cout << "The new iterator 'itStart' is pointing to " << *itStart << std::endl;
    std::cout << "The new iterator 'itEnd' is pointing to " << *itEnd << std::endl;
    
    ++itStart;
    --itStart;
    
    while (itStart != itEnd)
    {
        std::cout << *itStart << std::endl;
        ++itStart;
    }

    std::cout << "And now a example with lists!" << std::endl;
    
    std::list<int> s(mstack.begin(), mstack.end());
    std::list<int>::iterator sStart = s.begin();

    while (sStart != s.end())
    {
        std::cout << *sStart << std::endl;
        ++sStart;
    }
    
    return 0;
}

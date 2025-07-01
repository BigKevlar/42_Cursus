/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:01:52 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/10 20:15:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
    ./PmergeMe 3 5 9 7 4
    ./PmergeMe 7 8 27 100 11 46 53 2 0
    ./PmergeMe $(shuf -i 1-10000 -n 3000 | tr "\n" " ")
*/

int main(int ac, char **av)
{
    PmergeMe p;
    if (p.errorControl(ac, av)) {
        return 0;
    }

    std::cout << "Before: ";
    for (int i = 1; i < ac; i++) {
        std::cout << av[i] << " ";
    }
    std::cout << std::endl;
    
    struct timeval startV, endV;
    struct timeval startD, endD;
    double timeV;
    double timeD;
    
    p._v.clear();
    gettimeofday(&startV, NULL);
    p.fillContainers(ac, av);
    gettimeofday(&endV, NULL);
    timeV = ((endV.tv_sec - startV.tv_sec) * 1000000.0) + (endV.tv_usec - startV.tv_usec);
    
    p._d.clear();
    gettimeofday(&startD, NULL);
    p.fillContainers(ac, av);
    gettimeofday(&endD, NULL);
    timeD = ((endD.tv_sec - startD.tv_sec) * 1000000.0) + (endD.tv_usec - startD.tv_usec);
    
    std::cout << "After: ";
    for (size_t i = 0; i < p._v.size(); i++) {
        std::cout << p._v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque: " << timeD << " us" << std::endl;

    return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:13:57 by jmartos-          #+#    #+#             */
/*   Updated: 2025/01/16 13:28:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main() {
    std::deque<int> container01;
    std::vector<int> container02;
    for (int i = 0; i < 10; i++) {
        container01.push_back(i);
        container02.push_back(i);
    }
    int searching01 = 6;
    int searching02 = 42;
    std::cout << "Searching in container01..." << std::endl;
    try {
        *easyfind(container01, searching01);
        std::cout << "Found it! It's position in container01 is number " << *easyfind(container01, searching01) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Searching in container02..." << std::endl;
    try {
        *easyfind(container02, searching02);
        std::cout << "Found it! It's position in container02 is number " << *easyfind(container02, searching02) << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
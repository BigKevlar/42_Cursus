/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:37:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/26 13:44:23 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;
	
	std::cout << "* Here we use the standar constructor to create class 'a': *" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << "* Here we use the copy constructor to create class 'b' using 'a': *" << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << "* Here we use again the standar constructor to create class 'c' and the we put 'b' ins 'c': *" << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}

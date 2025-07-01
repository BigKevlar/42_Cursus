/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:37:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/26 16:36:50 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);
	
	std::cout << "* Here we use the standar constructor, to create a empty normal class. But we used a copy constructor copy constructor with a float number. *" << std::endl;
	std::cout << "a is " << a << std::endl;
	
	std::cout << "* Here we use the int number constructor, that creates 'b' class converting the int number pased by parameter in fixed number. *" << std::endl;
	std::cout << "b is " << b << std::endl;
	
	std::cout << "* Here we use the float number constructor, that creates 'c' class converting the float number pased by parameter in fixed number. *" << std::endl;
	std::cout << "c is " << c << std::endl;
	
	std::cout << "* Here we copy constructor, that creates 'd' class coping 'b' class. *" << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "* Here 'a' is a float number, and we convert it in a int number. *" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	
	std::cout << "Here 'b' is a int number, and we reconvert it in int number. *" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	
	std::cout << "Here 'c' is a float number, and we convert it in int number. *" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	
	std::cout << "Here 'd' is copy of 'b', an int number, and we reconvert it in int number. *" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return 0;
}

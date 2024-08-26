/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:37:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/26 19:26:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed	a;
	Fixed	const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	std::cout << "* We display the value of class 'a' as we initialized it at 0. *" << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "* We apply the preincrement operator to 'a', which minimum value associated with 8 bits is 0.00390625, and we display it. *" << std::endl;
	std::cout << ++a << std::endl;
	
	std::cout << "* We display 'a' after applying the preincrement operator, whose minimum associated value is the same, already saved in 'a'. *" << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "* Now we apply a postincrement operator, which will display the same thing as incrementing its value, but not the sumatory. *" << std::endl;
	std::cout << a++ << std::endl;
	
	std::cout << "* Now we display 'a', which will display the sum of the postincrement value with the value we get in 'a'. *" << std::endl;
	std::cout << a << std::endl;
	
	std::cout << "* We display 'b', which was created with a float constructor, to which we pass two values: a float copy constructor and an int. We return the result of the operator overload *, which multiplies the value passed to float plus the passed by parameters converted to float. *" << std::endl;
	std::cout << b << std::endl;
	
	std::cout << "* Here we simply display the larger of the two, either 'a' or 'b', which in this case is 'b'. *" << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << "* ¡OPCIONAL EXAMPLES! *" << std::endl;
	
	std::cout << "* The same has larger number but whit the smaler, which in this case is 'a'. *" << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;

	std::cout << "* That will rest the value for 0.00390625, so if we make this twice will be 0 again now. *" << std::endl;
	std::cout << --a << std::endl;
	std::cout << --a << std::endl;

	std::cout << "* Now the overload of comparision operators. *" << std::endl;
	if (a < b)
		std::cout << "* 'a' is less than 'b'. *" << std::endl;
	if (a != b)
		std::cout << "* 'a' and 'b' are diferent. *" << std::endl;
	
	return 0;
}

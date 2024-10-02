/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:39:22 by jmartos-          #+#    #+#             */
/*   Updated: 2024/10/02 16:17:52 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int a = 42;
	int b = 24;
	float c = 24.24;
	float d = 42.42;
	std::string e = "hola";
	std::string f = "mundo";

	std::cout << std::endl;
	std::cout << "El valor de 'a' es: " << a << std::endl;
	std::cout << "El valor de 'b' es: " << b << std::endl;
	std::cout << "El valor de 'c' es: " << c << std::endl;
	std::cout << "El valor de 'd' es: " << d << std::endl;
	std::cout << "El valor de 'e' es: " << e << std::endl;
	std::cout << "El valor de 'f' es: " << f << std::endl;
	std::cout << std::endl;
	std::cout << "El mayor entre 'a' y 'b' es: " << max(a, b) << std::endl;
	std::cout << "El mayor entre 'c' y 'd' es: " << max(c, d) << std::endl;
	std::cout << "El mayor entre 'e' y 'f' es: " << ::max(e, f) << std::endl;
	std::cout << "El menor entre 'a' y 'b' es: " << min(a, b) << std::endl;
	std::cout << "El menor entre 'a' y 'b' es: " << min(c, d) << std::endl;
	std::cout << "El menor entre 'e' y 'f' es: " << ::min(e, f) << std::endl;
	swap(a, b);
	swap(c, d);
	swap(e, f);
	std::cout << "Ahora 'a' es: " << a << std::endl;
	std::cout << "Ahora 'b' es: " << b << std::endl;
	std::cout << "Ahora 'c' es: " << c << std::endl;
	std::cout << "Ahora 'd' es: " << d << std::endl;
	std::cout << "Ahora 'e' es: " << e << std::endl;
	std::cout << "Ahora 'f' es: " << f << std::endl;
}

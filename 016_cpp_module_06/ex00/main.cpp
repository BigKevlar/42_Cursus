/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:20:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/27 18:58:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "The number of argument values is not correct." << std::endl;
		return(1);
	}
	ScalarConverter input(argv[1]);
	input.convertionChar();
	input.convertionInt();
	input.convertionFloat();
	input.convertionDouble();
	return (0);
}

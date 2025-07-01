/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:10:17 by jmartos-          #+#    #+#             */
/*   Updated: 2025/02/04 16:26:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: there's no file to open." << std::endl;
		return 0;
	}
	BitcoinExchange container;
	container.checkInput(av[1]);
	return 0;    
}
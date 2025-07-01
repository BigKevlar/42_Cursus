/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 20:24:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main()
{
	Harl	Harl;
	
	std::cout << "- DEBUG" << std::endl;
	Harl.complain("DEBUG");
	std::cout << "- INFO" << std::endl;
	Harl.complain("INFO");
	std::cout << "- WARNING" << std::endl;
	Harl.complain("WARNING");
	std::cout << "- ERROR" << std::endl;
	Harl.complain("ERROR");
}

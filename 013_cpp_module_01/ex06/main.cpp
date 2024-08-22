/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 20:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/22 20:46:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	Harl;
	
    if (ac == 2)
		Harl.filter(av[1]);
    else
    {
        std::cout << "Error! Arguments incorrect." << std::endl;
		return (0);
    }
}

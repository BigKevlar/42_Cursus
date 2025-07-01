/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:02:59 by jmartos-          #+#    #+#             */
/*   Updated: 2024/10/02 21:44:06 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int		arr0[6] = {1,2,3,4,5,6};
	double	arr1[6] = {42.1,42.2,42.3,42.4,42.5,42.6};
	char 	arr2[6] = {'h','o','l','a','4','2'};
	
	std::cout << std::endl;
	iter(arr0, 6, print);
	std::cout << std::endl;
	iter(arr1, 6, print);
	std::cout << std::endl;
	iter(arr2, 6, print);
	std::cout << std::endl;
}

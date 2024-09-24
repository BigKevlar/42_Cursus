/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:58 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 17:19:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << std::endl;
	try
	{
		Intern intern0;
		AForm *form0;

		form0 = intern0.makeForm("RobotomyRequestForm", "42Staff");
		std::cout << *(form0) << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}

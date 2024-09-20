/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:58 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/20 14:59:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_0" << std::endl;
		try
		{
			Bureaucrat human0;
			std::cout << human0 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_1" << std::endl;
		try
		{
			Bureaucrat human1("Juan", 1042);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_2" << std::endl;
		try
		{
			Bureaucrat human2("Ale", -42);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_3" << std::endl;
		try
		{
			Bureaucrat human3("Victor", 42);
			human3.upGrade();
			std::cout << human3 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_4" << std::endl;
		try
		{
			Bureaucrat human4("Nestor", 42);
			human4.downGrade();
			std::cout << human4 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_5" << std::endl;
		try
		{
			Bureaucrat human5("Leia", 1);
			human5.upGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_6" << std::endl;
		try
		{
			Bureaucrat human6("Luis", 150);
			human6.downGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}

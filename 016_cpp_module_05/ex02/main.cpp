/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:58 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 13:22:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << std::endl;
	Bureaucrat jmartos("jmartos", 150);
	Bureaucrat arosas("arosas", 120);
	Bureaucrat vzurera("vzurera", 3);
	ShrubberyCreationForm shrubbery("House");
	RobotomyRequestForm robotomy("Curie");
	PresidentialPardonForm presidential("Pedro Sanchez");
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_0" << std::endl;
		try
		{
			std::cout << jmartos << std::endl;
			std::cout << shrubbery << std::endl;
			jmartos.executeForm(shrubbery);
			jmartos.executeForm(robotomy);
			jmartos.executeForm(presidential);
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
			std::cout << arosas << std::endl;
			std::cout << shrubbery << std::endl;
			arosas.executeForm(shrubbery);
			shrubbery.beSigned(arosas);
			arosas.executeForm(shrubbery);
			std::cout << shrubbery << std::endl;
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
			std::cout << vzurera << std::endl;
			std::cout << robotomy << std::endl;
			std::cout << presidential << std::endl;
			robotomy.beSigned(vzurera);
			presidential.beSigned(vzurera);
			std::cout << robotomy << std::endl;
			std::cout << presidential << std::endl;
			vzurera.executeForm(robotomy);
			vzurera.executeForm(presidential);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}

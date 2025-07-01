/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:58 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/20 14:59:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << std::endl;
	{
		std::cout << "EXAMPLE_0" << std::endl;
		try
		{
			Form form0;
			std::cout << form0 << std::endl;
			Form form1("form1", false, 42, 42);
			std::cout << form1 << std::endl;
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
			Bureaucrat human0("Juan", 42);
			std::cout << human0 << std::endl;
			Form form2("form2", false, 43, 43);
			std::cout << form2 << std::endl;
			form2.beSigned(human0);
			human0.signForm(form2);
			std::cout << form2 << std::endl;
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
			Bureaucrat human1("Impostor", 10);
			std::cout << human1 << std::endl;
			Form form3("form3", true, 50, 50);
			Form form4("form4", true, 3, 3);
			std::cout << form3 << std::endl;
			std::cout << form4 << std::endl;
			form3.beSigned(human1);
			human1.signForm(form3);
			std::cout << form3 << std::endl;
			form4.beSigned(human1);
			human1.signForm(form4);
			std::cout << form4 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:33:15 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 16:32:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		AForm *form[3];
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy_);
		Intern	&operator=(const Intern &copy_);
		AForm	*makeForm(const std::string formName_, const std::string targetForm_);
		class FailedFormException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Intern &form);

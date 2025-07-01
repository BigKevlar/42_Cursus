/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:59:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/23 16:23:25 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string name_, unsigned int grade_);
		Bureaucrat(const Bureaucrat &copy_);
		Bureaucrat &operator=(const Bureaucrat &copy_);
		const std::string	&getName(void) const;
		unsigned int const	&getGrade(void) const;
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
		void	upGrade(void);
		void	downGrade(void);
		void	signForm(AForm &form);
		void	executeForm(const AForm &form);
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat &form);

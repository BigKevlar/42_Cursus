/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/20 14:38:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		bool				_sign;
		const unsigned int	_grade2Sign;
		const unsigned int	_grade2Execute;
	public:
		AForm();
		~AForm();
		AForm(const std::string name_, bool signed_, const unsigned int	grade2Sign_, const unsigned int grade2Execute_);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		const std::string	&getName(void);
		bool				&getSign(void);
		const unsigned int	&getGrade2Sign(void);
		const unsigned int	&getGrade2Execute(void);
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
		void	beSigned(Bureaucrat &bureaucrat);
		void	signForm(Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &str, AForm &ref);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:59:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/19 17:33:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string name_, unsigned int grade_);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy);
		const std::string	&getName(void);
		unsigned int		&getGrade(void);
		class GradeHighException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
		class GradeLowException: public std::exception
		{
			public:
				virtual char const	*what() const throw();
		};
		void	upGrade(void);
		void	downGrade(void);
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat &ref);

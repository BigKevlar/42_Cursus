/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:59:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/13 13:20:25 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(150)
{
	std::cout << "[ Default constructor called! ]" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[ Destructor called! ]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy_)
{
	std::cout << "[ Copy constructor called! ]" << std::endl;
	*this = copy_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ Coping... ]" << std::endl;
		_grade = copy_._grade;
		return (*this);
	}
	else
	{
		std::cout << "[ Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

const std::string	&Bureaucrat::getName(void)
{
	return (this->_name);
}

unsigned int	&Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

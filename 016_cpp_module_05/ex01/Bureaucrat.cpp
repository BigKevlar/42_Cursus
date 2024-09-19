/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:59:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/19 17:32:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("NPC"), _grade(150)
{
	std::cout << "[ Default constructor called! ]" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[ Destructor called! ]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name_, unsigned int grade_): _name(name_), _grade(grade_)
{
	std::cout << "[ Constructor called! ]" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy_): _name(copy_._name), _grade(copy_._grade)
{
	std::cout << "[ Copy constructor called! ]" << std::endl;
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

std::ostream	&operator<<(std::ostream &str, Bureaucrat &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

const std::string	&Bureaucrat::getName(void)
{
	return (this->_name);
}

unsigned int	&Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

char const	*Bureaucrat::GradeHighException::what() const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Bureaucrat::upGrade(void)
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeHighException());
	else
		_grade -= 1;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeLowException());
	else
		_grade += 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:59:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/20 15:31:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("NPC"), _grade(150)
{
	std::cout << "[ (B) Default constructor called! ]" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[ (B) Destructor called! ]" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name_, unsigned int grade_): _name(name_), _grade(grade_)
{
	std::cout << "[ (B) Constructor called! ]" << std::endl;
	if (grade_ < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade_ > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy_) : _name(copy_._name), _grade(copy_._grade)
{
	std::cout << "[ (B) Copy constructor called! ]" << std::endl;
	*this = copy_;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (B) Coping... ]" << std::endl;
		_grade = copy_._grade;
		return (*this);
	}
	else
	{
		std::cout << "[ (B) Same info. Copy abort! ]" << std::endl;
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

char const	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Bureaucrat::upGrade(void)
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		_grade -= 1;
}

void	Bureaucrat::downGrade(void)
{
	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		_grade += 1;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because: " << e.what() << std::endl;
	}
}
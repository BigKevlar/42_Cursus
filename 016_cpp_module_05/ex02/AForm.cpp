/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:06 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/20 15:30:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("defaultForm"), _sign(false), _grade2Sign(150), _grade2Execute(150)
{
	std::cout << "[ (F) Default constructor called! ]" << std::endl;
}

Form::~Form()
{
	std::cout << "[ (F) Destructor called! ]" << std::endl;
}

Form::Form(const std::string name_, bool sign_, const unsigned int grade2Sign_, const unsigned int grade2Execute_) : _name(name_), _sign(sign_), _grade2Sign(grade2Sign_), _grade2Execute(grade2Execute_)
{
	std::cout << "[ (F) Constructor called! ]" << std::endl;
	if (sign_== true)
		sign_= false;
	if (grade2Sign_ < 1)
		throw (Form::GradeTooHighException());
	if (grade2Sign_ > 150)
		throw (Form::GradeTooLowException());
	if (grade2Execute_ < 1)
		throw (Form::GradeTooHighException());
	if (grade2Execute_ > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &copy_) : _name(copy_._name), _sign(copy_._sign), _grade2Sign(copy_._grade2Sign), _grade2Execute(copy_._grade2Execute)
{
	std::cout << "[ (F) Copy constructor called! ]" << std::endl;
	*this = copy_;
}

Form &Form::operator=(const Form &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ Coping... ]" << std::endl;
		_sign = copy_._sign;
		return (*this);
	}
	else
	{
		std::cout << "[ Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::ostream	&operator<<(std::ostream &str, Form &form)
{
	return (str << form.getName() << " form, signed status " << form.getSign() << ", grade to sign " << form.getGrade2Sign() << ", grade to execute " << form.getGrade2Sign());
}

const std::string	&Form::getName(void)
{
	return (this->_name);
}

bool	&Form::getSign(void)
{
	return (this->_sign);
}

const unsigned int	&Form::getGrade2Sign(void)
{
	return (this->_grade2Sign);
}

const unsigned int	&Form::getGrade2Execute(void)
{
	return (this->_grade2Execute);
}

char const	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGrade2Sign())
		throw (GradeTooLowException());
	else
		_sign = true;
}


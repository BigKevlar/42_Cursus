/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:06 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 16:21:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm() : _name("defaultForm"), _sign(false), _grade2Sign(150), _grade2Execute(150)
{
	std::cout << "[ (AF) Default constructor called! ]" << std::endl;
}

AForm::AForm(const std::string name_, bool sign_, const unsigned int grade2Sign_, const unsigned int grade2Execute_) : _name(name_), _sign(sign_), _grade2Sign(grade2Sign_), _grade2Execute(grade2Execute_)
{
	std::cout << "[ (AF) Constructor called! ]" << std::endl;
	if (sign_== true)
		sign_= false;
	if (grade2Sign_ < 1)
		throw (AForm::GradeTooHighException());
	if (grade2Sign_ > 150)
		throw (AForm::GradeTooLowException());
	if (grade2Execute_ < 1)
		throw (AForm::GradeTooHighException());
	if (grade2Execute_ > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &copy_) : _name(copy_._name), _sign(copy_._sign), _grade2Sign(copy_._grade2Sign), _grade2Execute(copy_._grade2Execute)
{
	std::cout << "[ (AF) Copy constructor called! ]" << std::endl;
	*this = copy_;
}

AForm &AForm::operator=(const AForm &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (AF) Coping... ]" << std::endl;
		_sign = copy_._sign;
		return (*this);
	}
	else
	{
		std::cout << "[ (AF) Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::ostream	&operator<<(std::ostream &str, AForm &form)
{
	return (str << form.getName() << " form, signed status " << form.getSign() << ", grade to sign " << form.getGrade2Sign() << ", grade to execute " << form.getGrade2Execute());
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

bool const	&AForm::getSign(void) const
{
	return (this->_sign);
}

const unsigned int	&AForm::getGrade2Sign(void) const
{
	return (this->_grade2Sign);
}

const unsigned int	&AForm::getGrade2Execute(void) const
{
	return (this->_grade2Execute);
}

char const	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

char const	*AForm::NoSignedException::what(void) const throw()
{
	return ("Form is no signed");
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGrade2Sign())
		throw (GradeTooLowException());
	else
		_sign = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_sign == false)
		throw (AForm::NoSignedException());
	else if (executor.getGrade() > this->_grade2Sign)
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << executor.getName() << " executed " << this->_name << std::endl;
		this->executing(executor);
	}
}

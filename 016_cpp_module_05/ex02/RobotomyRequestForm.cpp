/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:06 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/23 18:44:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("defaultRobotomyRequestForm", false, 72, 45), _target("defaultTarget_robotomy")
{
	std::cout << "[ (RRF) Default constructor called! ]" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[ (RRF) Destructor called! ]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_) : AForm("RobotomyRequestForm", false, 72, 45), _target(target_)
{
	std::cout << "[ (RRF) Constructor called! ]" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy_) : AForm(copy_), _target(copy_._target)
{
	std::cout << "[ (RRF) Copy constructor called! ]" << std::endl;
	*this = copy_;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (RRF) Coping... ]" << std::endl;
		AForm::operator=(copy_);
		_target = copy_._target;
		return (*this);
	}
	else
	{
		std::cout << "[ (RRF) Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm &form)
{
	return (str << form.getName() << " form, signed status " << form.getSign() << ", grade to sign " << form.getGrade2Sign() << ", grade to execute " << form.getGrade2Execute());
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::executing(Bureaucrat const &executor) const
{
	(void)executor;
	bool	success;

	std::cout << "BRRRRRRR DDDRRRRRRR GRRRRRRR!!! ...PISSSSHHHHH..." << std::endl;
	srand(static_cast<unsigned>(time(NULL)));
	success = rand() % 2;
	if (success)
		std::cout << this->_target << " robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}

/*//////////////////////////////////////////////////////////////////////////////*/
/* Makes some drilling noises. Then, informs that <target> has been robotomized */
/* (successfully 50% of the time). Otherwise, informs that the robotomy failed. */
/*//////////////////////////////////////////////////////////////////////////////*/
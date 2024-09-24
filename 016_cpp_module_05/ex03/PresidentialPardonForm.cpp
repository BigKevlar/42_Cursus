/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:06 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/23 18:50:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("defaultPresidentialPardonForm", false, 25, 5), _target("defaultTarget_presidential")
{
	std::cout << "[ (PPF) Default constructor called! ]" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[ (PPF) Destructor called! ]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target_) : AForm("PresidentialPardonForm", false, 25, 5), _target(target_)
{
	std::cout << "[ (PPF) Constructor called! ]" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy_) : AForm(copy_), _target(copy_._target)
{
	std::cout << "[ (PPF) Copy constructor called! ]" << std::endl;
	*this = copy_;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (PPF) Coping... ]" << std::endl;
		AForm::operator=(copy_);
		_target = copy_._target;
		return (*this);
	}
	else
	{
		std::cout << "[ (PPF) Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm &form)
{
	return (str << form.getName() << " form, signed status " << form.getSign() << ", grade to sign " << form.getGrade2Sign() << ", grade to execute " << form.getGrade2Execute());
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::executing(Bureaucrat const &executor) const
{
	(void)executor;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

/*///////////////////////////////////////////////////////////////*/
/* Informs that <target> has been pardoned by Zaphod Beeblebrox. */
/*///////////////////////////////////////////////////////////////*/
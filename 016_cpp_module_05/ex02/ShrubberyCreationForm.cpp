/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:06 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/23 18:27:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defaultShrubberyCreationForm", false, 145, 137), _target("defaultTarget")
{
	std::cout << "[ (SCF) Default constructor called! ]" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ (SCF) Destructor called! ]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target_)
{
	std::cout << "[ (SCF) Constructor called! ]" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy_) : AForm(copy_), _target(copy_._target)
{
	std::cout << "[ (SCF) Copy constructor called! ]" << std::endl;
	*this = copy_;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy_)
{
	if (this != &copy_)
	{
		std::cout << "[ (SCF) Coping... ]" << std::endl;
		AForm::operator=(copy_);
		_target = copy_._target;
		return (*this);
	}
	else
	{
		std::cout << "[ (SCF) Same info. Copy abort! ]" << std::endl;
		return (*this);
	}
}

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm &form)
{
	return (str << form.getName() << " form, signed status " << form.getSign() << ", grade to sign " << form.getGrade2Sign() << ", grade to execute " << form.getGrade2Execute());
}

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::executing(Bureaucrat const &executor) const
{
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream outfile(filename);
	if (!outfile.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
	outfile << "	    oxoxoo    ooxoo"
				"	  ooxoxo oo  oxoxooo"
				"	 oooo xxoxoo ooo ooox"
				"	 oxo o oxoxo  xoxxoxo"
				"	  oxo xooxoooo o ooo"
				"	    ooo\\oo\\  /o/o"
				"	        \\  \\/ /"
				"	         |   /"
				"	         |  |"
				"	         | D|"
				"	         |  |"
				"	         |  |"
				"	  ______/____\\____";
	outfile.close();
}

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/* Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it. */
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
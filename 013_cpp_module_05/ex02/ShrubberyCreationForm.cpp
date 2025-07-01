/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:06 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 13:27:22 by jmartos-         ###   ########.fr       */
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

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm &form)
{
	return (str << form.getName() << " form, signed status " << form.getSign() << ", grade to sign " << form.getGrade2Sign() << ", grade to execute " << form.getGrade2Execute());
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::executing(Bureaucrat const &executor) const
{
	(void)executor;
	std::string filename = getTarget() + "_shrubbery";
	std::cout << "Filename: " << filename << std::endl;
	std::ofstream outfile(filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return;
	}
	outfile << "	    oxoxoo    ooxoo\n"
			   "	  ooxoxo oo  oxoxooo\n"
			   "	 oooo xxoxoo ooo ooox\n"
			   "	 oxo o oxoxo  xoxxoxo\n"
			   "	  oxo xooxoooo o ooo\n"
			   "	    ooo\\oo\\  /o/o\n"
			   "	        \\  \\/ /\n"
			   "	         |   /\n"
			   "	         |  |\n"
			   "	         | D|\n"
			   "	         |  |\n"
			   "	         |  |\n"
			   "	  ______/____\\____\n";
	std::cout << "Arbol escrito en: " << filename << std::endl;
	outfile.close();
	std::cout << "Archivo cerrado correctamente." << std::endl;
}

/*//////////////////////////////////////////////////////////////////////////////////////////////*/
/* Create a file <target>_shrubbery in the working directory, and writes ASCII trees inside it. */
/*//////////////////////////////////////////////////////////////////////////////////////////////*/
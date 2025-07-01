/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:38:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 16:49:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "[ (I) Default constructor called! ]" << std::endl;
}

Intern::~Intern()
{
	std::cout << "[ (I) Destructor called! ]" << std::endl;
	delete form[0];
    delete form[1];
    delete form[2];
}

Intern::Intern(const Intern &copy_)
{
    std::cout << "[ (I) Copy constructor called! ]" << std::endl;
    form[0] = new ShrubberyCreationForm(*dynamic_cast<ShrubberyCreationForm*>(copy_.form[0]));
    form[1] = new RobotomyRequestForm(*dynamic_cast<RobotomyRequestForm*>(copy_.form[1]));
    form[2] = new PresidentialPardonForm(*dynamic_cast<PresidentialPardonForm*>(copy_.form[2]));
}

Intern &Intern::operator=(const Intern &copy_)
{
    std::cout << "[ (I) Assignment operator called! ]" << std::endl;
    if (this != &copy_)
    {
        // Libera la memoria de los formularios actuales
        delete form[0];
        delete form[1];
        delete form[2];

        // Crea nuevas instancias de formularios
        form[0] = new ShrubberyCreationForm(*dynamic_cast<ShrubberyCreationForm*>(copy_.form[0]));
        form[1] = new RobotomyRequestForm(*dynamic_cast<RobotomyRequestForm*>(copy_.form[1]));
        form[2] = new PresidentialPardonForm(*dynamic_cast<PresidentialPardonForm*>(copy_.form[2]));
    }
    return *this;
}

const char	*Intern::FailedFormException::what(void) const throw()
{
	return ("Form creation failed");
}

AForm *Intern::makeForm(const std::string _formName, const std::string _formTarget)
{
	form[0] = new ShrubberyCreationForm(_formTarget);
	form[1] = new RobotomyRequestForm(_formTarget);
	form[2] = new PresidentialPardonForm(_formTarget);

	for(int i=0; i<3; i++)
	{
		if (_formName == form[i]->getName())
			return (form[i]);
	}
	throw FailedFormException();
}

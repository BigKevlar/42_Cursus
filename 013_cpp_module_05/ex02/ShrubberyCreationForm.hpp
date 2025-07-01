/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:56:07 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 12:44:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy_);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy_);
		const std::string	&getTarget(void) const;
		void				executing(const Bureaucrat &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm &form);

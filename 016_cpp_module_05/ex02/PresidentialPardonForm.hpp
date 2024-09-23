/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:56:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/23 18:44:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;
	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		PresidentialPardonForm(const PresidentialPardonForm &copy_);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy_);
		const std::string	&getTarget(void) const;
		void				executing(const Bureaucrat &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm &form);

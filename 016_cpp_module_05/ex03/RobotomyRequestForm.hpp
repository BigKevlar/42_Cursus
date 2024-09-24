/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:56:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/24 12:44:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		RobotomyRequestForm(const RobotomyRequestForm &copy_);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy_);
		const std::string	&getTarget(void) const;
		void				executing(const Bureaucrat &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm &form);

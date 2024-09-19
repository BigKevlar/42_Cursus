/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/19 17:36:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form
{
	private:
		const std::string	_name;
		unsigned int		_grade;
		bool				_signed;
		const unsigned int	_gradeRequired;
	public:
		Form();
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &copy);
};

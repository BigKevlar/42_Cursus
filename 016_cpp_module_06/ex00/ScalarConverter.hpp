/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:27:20 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/25 20:33:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>

class ScalarConverter
{
	private:
		char		*_inputC;
		std::string	_inputCPP;
		bool		_imposible;
		double		_value;
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(char* inputC_);
		ScalarConverter(const ScalarConverter &copy_);
		ScalarConverter &operator=(const ScalarConverter &copy_);
		void	convertionChar(void);
		void	convertionInt(void);
		void	convertionFloat(void);
		void	convertionDouble(void);
};

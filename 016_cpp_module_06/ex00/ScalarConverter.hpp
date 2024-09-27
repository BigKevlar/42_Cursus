/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:27:20 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/27 18:53:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
#include <sstream>	// std::stringstream (string -> double)
#include <iomanip>	//std::cout << std::fixed
					//std::setprecision(1)

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

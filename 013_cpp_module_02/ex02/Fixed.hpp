/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:49:23 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/25 21:26:51 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath> // Para usar "roundf"

class Fixed
{
	private:
		int					_fixed_point_number;
		static const int	_bits;
	public:
		/* Constructores y destructor. */
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int int_number);
		Fixed(const float float_number);
		~Fixed();
		/* Operador de copia. */
		Fixed	&operator=(const Fixed &copy);
		/* Operadores de comparacion, para sobrecargar. */
		bool	operator>(const Fixed &copy) const;
		bool	operator<(const Fixed &copy) const;
		bool	operator>=(const Fixed &copy) const;
		bool	operator<=(const Fixed &copy) const;
		bool	operator==(const Fixed &copy) const;
		bool	operator!=(const Fixed &copy) const;
		/* Operadores aritmeticos, para sobrecargar. */
		Fixed	operator+(const Fixed &copy);
		Fixed	operator-(const Fixed &copy);
		Fixed	operator*(const Fixed &copy);
		Fixed	operator/(const Fixed &copy);
		/* Operadores de postincremento y postdecremento, para sobrecargar. */
		Fixed	operator++(int _fixed_point_number);
		Fixed	operator--(int _fixed_point_number);
		/* Operadores de preincremento y predecremento, para sobrecargar. */
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		/* Funciones de clase. */
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static const Fixed	&min(const Fixed &copy1, const Fixed &copy2);
		static const Fixed	&max(const Fixed &copy1, const Fixed &copy2);
};

/* Operador de sobrecarga. */
std::ostream	&operator<<(std::ostream &outputStream, const Fixed &_fixed_point_number);

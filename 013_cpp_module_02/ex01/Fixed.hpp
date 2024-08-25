/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:49:23 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/25 17:56:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int					_fixed_point_number;
		const static int	_bits;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int number);
		Fixed(const float number);
		~Fixed();
		Fixed	&operator=(const Fixed &copy);
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

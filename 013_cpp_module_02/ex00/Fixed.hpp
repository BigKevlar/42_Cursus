/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:49:23 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 18:55:11 by jmartos-         ###   ########.fr       */
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
		Fixed(); // OBLIGATORIO!
		Fixed(const Fixed &copy); // OBLIGATORIO!
		~Fixed(); // OBLIGATORIO!
		Fixed	&operator=(const Fixed &copy); // OBLIGATORIO!
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

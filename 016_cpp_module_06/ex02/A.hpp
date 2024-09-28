/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:09:04 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/28 17:59:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Base
{
	private:
	public:
		Base();
		virtual ~Base();
		Base(const Base &copy_);
		Base	&operator=(const Base &copy_);
};

/* subject: These four classes don’t have to be designed in the Orthodox Canonical Form.*/
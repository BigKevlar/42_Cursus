/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:09:25 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/31 16:22:47 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &copy_);
		virtual	~Brain();
		Brain 		&operator=(const Brain &copy_);
		std::string	ideas_[100];
};

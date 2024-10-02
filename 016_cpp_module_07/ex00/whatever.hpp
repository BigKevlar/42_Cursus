/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:30:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/10/02 21:06:46 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename S>
void	swap(S &x, S &y)
{
	S temp = x;
	x = y;
	y = temp;
}

template <typename N>
const N	&min(const N &x ,const N &y)
{
	if (x <= y)
		return (x);
	else
		return (y);
}

template <typename M>
const M	&max(const M &x ,const M &y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

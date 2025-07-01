/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 20:54:44 by jmartos-          #+#    #+#             */
/*   Updated: 2024/10/02 21:42:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename P>
void print(const P character)
{
	std::cout << character << " ";
}

template <typename T, typename Y>
// El ultimo parametro significa "una funcion que llama a todos los elementos del array".
void	iter(const T *arrayDir, const Y arrayLen, void (*func)(const T &))
{
	if (arrayDir == NULL || func == NULL)
		return ;
	for (int i = 0; i < arrayLen; i++)
		print(arrayDir[i]);
}

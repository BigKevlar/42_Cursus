/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:25:28 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/22 22:39:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

int	ft_word_counter(char const *str, char letter)
{
	int	c;
	int	w_cont;

	c = 0;
	w_cont = 0;
	while (str[c] != '\0')
	{
		if (str[c] != letter)
		{
			w_cont++;
			while (str[c] != letter && str[c] != '\0')
				c++;
		}
		else
			c++;
	}
	return (w_cont);
}

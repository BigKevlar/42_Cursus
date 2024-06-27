/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:25:28 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/21 18:31:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	w_cont;

	i = 0;
	w_cont = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w_cont++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (w_cont);
}

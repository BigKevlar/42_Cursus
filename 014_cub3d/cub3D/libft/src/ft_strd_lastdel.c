/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_lastdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:10:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/08/17 17:21:49 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h" /* Libreria 42 "jmartos-". */

char	**ft_strd_lastdel(char **str)
{
	char	**new;
	int		len;
	int		c;

	len = ft_strd_len(str);
	new = ft_calloc(len, sizeof(char *));
	c = 0;
	while (c < len - 1)
	{
		new[c] = ft_strdup(str[c]);
		c++;
	}
	ft_strd_free(str);
	return (new);
}

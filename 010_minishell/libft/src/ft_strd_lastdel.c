/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_lastdel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:10:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/08 10:17:47 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

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

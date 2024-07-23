/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:58:01 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/08 19:34:24 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

char	**ft_strd_add(char **str, char *add)
{
	int		temp_len;
	int		len;
	char	**new;

	len = ft_strd_len(str);
	temp_len = len;
	new = ft_calloc(sizeof(char *), len + 2);
	while (len--)
		new[len] = ft_strdup(str[len]);
	new[temp_len] = ft_strdup(add);
	ft_strd_free(str);
	return (new);
}

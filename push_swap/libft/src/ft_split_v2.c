/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:00:35 by jmartos-          #+#    #+#             */
/*   Updated: 2024/02/26 16:35:25 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter_v2(const char *str, char c)
{
	size_t	cont1;
	size_t	cont2;

	cont1 = 0;
	cont2 = 0;
	while (str[cont1] != '\0')
	{
		if (str[cont1] != c && (str[cont1 + 1] == c || str[cont1 + 1] == '\0'))
			cont2++;
		cont1++;
	}
	return (cont2);
}

static char	**ft_free_split_v2(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

char	**ft_split_v2(char const *s, char c)
{
	char	**str;
	size_t	cont1;
	int		cont2;

	str = malloc(sizeof(char *) * (ft_counter_v2(s, c) + 1));
	if (!str)
		return (NULL);
	cont2 = -1;
	while (*s)
	{
		if (*s != c)
		{
			cont1 = 0;
			while (s[cont1] && s[cont1] != c)
				cont1++;
			str[++cont2] = ft_substr(s, 0, cont1);
			if (!str[cont2])
				return (ft_free_split_v2(str, cont2));
			s += cont1;
		}
		else
			s++;
	}
	str[++cont2] = NULL;
	return (str);
}

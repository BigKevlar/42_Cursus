/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:00:35 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:27:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#La función principal reserva en memoria una cadena de strings "s"
en substrings usando un delimitador "c" para separarlos entre si.
Para ello, usamos antes la subfunción "ft_counter" para iterar entre caracteres,
y al final usamos "ft_free_split" para liberar la memoria utilizada.#*/
static size_t	ft_counter(const char *str, char c)
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

static char	**ft_free_split(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cont1;
	int		cont2;

	str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
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
				return (ft_free_split(str, cont2));
			s += cont1;
		}
		else
			s++;
	}
	str[++cont2] = NULL;
	return (str);
}

/*(...main en desarrollo...)*/
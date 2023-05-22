/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:00:35 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/22 12:15:49 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
LA FUNCION PRINCIPAL "ft_split", QUE RESERVA UN ARRAY DE STRINGS
EN SUBSTRINGS USANDO "c" COMO DELIMITADOR ENTRE ELLOS.
PARA ELLO USAMOS ANTES UNA FUNCION PARA IR ITERANDO ENTRE CARACTERES.
*/
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

static void	ft_free_split(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
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
			while (*s != 0 && *s != c)
			{
				cont1++;
				s++;
			}
			str[++cont2] = ft_substr(s - cont1, 0, cont1);
			if (!str[cont2])
			{
				ft_free_split(str, cont2);
				return (NULL);
			}
		}
		else
			s++;
	}
	str[++cont2] = NULL;
	return (str);
}

/*
(FUNCION FREE PARA FT_SPLIT)
	static void	ft_free_split(char **str, size_t i)
	{
		while (i > 0)
		{
			i--;
			free(str[i]);
		}
		free(str);
	}
(FUNCION FT_FREE_SPLIT EN FT_SPLIT)
	if (!str[cont2])
	{
		ft_free_split(str, cont2);
		return (NULL);
	}
*/
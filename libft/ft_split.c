/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:00:35 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/21 17:04:17 by jmartos-         ###   ########.fr       */
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

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cont1;
	size_t	cont2;

	str = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!str)
		return (NULL);
	cont2 = 0;
	while (*s)
	{
		if (*s != c)
		{
			cont1 = 0;
			while (*s && *s != c)
			{
				cont1++;
				s++;
			}
			str[cont2++] = ft_substr(s - cont1, 0, cont1);
		}
		else
			s++;
	}
	str[cont2] = NULL;
	return (str);
}

/*
(ESTA PARTE ES UNA PRUEBA PARA PROBAR UNA FUNCION FREE, PERO SUPERA 25 LINEAS)
static void	ft_free_split(char **str, size_t i)
{
	while (i >= 0)
		free(str[i]--);
	free(str);
}
(Y ESTA PARTE VA EN "ft_split" EN EL ULTIMO BUCLE)
	if (!str[del - 1])
		return (ft_free_split(str, del - 1));
	s += len;
	if (!str[cont2])
	{
		ft_free_split(str, cont2 - 1);
		return (NULL);
	}
	s += cont1;
*/
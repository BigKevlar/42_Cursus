/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:11:02 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/18 14:18:35 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
(a partir de estas funciones vamos a empezar a declarar los valores
de las variables antes de la parte en la que van a usarse, por claridad)
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s_len < start)
		return (ft_strdup(""));
	if (s_len + start < len)
		len = s_len + start;
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

/*OPCION DOS (EN REVISION)*/
/*
{
	size_t	cont1;
	size_t	cont2;
	char	*str;

	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	cont1 = 0;
	cont2 = 0;
	while (s[cont1])
	{
		if (cont1 >= start && cont2 < len)
		{
			str[cont2] = s[cont1];
			cont2++;
		}
		cont1++;
	}
	str[cont2] = '\0';
	return (str);
}
*/
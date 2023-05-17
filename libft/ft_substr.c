/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:11:02 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/17 13:21:15 by jmartos-         ###   ########.fr       */
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
	size_t	cont1;
	size_t	cont2;
	char	*substring;

	substring = malloc(ft_strlen(s) * (len + 1));
	if (!substring)
		return (NULL);
	cont1 = 0;
	cont2 = 0;
	while (s[cont1])
	{
		if (cont1 >= start && cont2 < len)
		{
			substring[cont2] = s[cont1];
			cont2++;
		}
		cont1++;
	}
	substring[cont2] = 0;
	return (substring);
}

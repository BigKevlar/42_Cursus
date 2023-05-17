/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:15:46 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/17 14:02:23 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
(a partir de estas funciones vamos a empezar a declarar los valores
de las variables antes de la parte en la que van a usarse, por claridad)
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	cont1;
	size_t	cont2;
	char	*substring;

	substring = malloc(ft_strlen(s) + 1);
	if (!substring)
		return (NULL);
	cont1 = 0;
	cont2 = 0;
	while (s2[cont2] && (cont1 + cont2 + 1) < size)
	{
		s1[cont1 + cont2] = s2[cont2];
		cont2++;
	}
	if (cont1 < size)
		s1[cont1 + cont2] = '\0';
	return (ft_strcpy(substring, s1, cont1 + cont2));
}

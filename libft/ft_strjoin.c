/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:15:46 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/17 14:39:45 by jmartos-         ###   ########.fr       */
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
	char	*substring;

	substring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!substring)
		return (NULL);
	if (substring)
		ft_strlcpy(substring, s1, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (substring);
}

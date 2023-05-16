/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:19:57 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/16 13:07:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
ESTA FUNCION BUSCA LA CADENA "needle" (aguja) EN LAS PRIMERAS "len" POSICIONES
DE LA CADENA "haystack" (pajar). 
(Nota: tenemos que avanzar con dos blucles/dos contadores).
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c2 = 0;
	if (needle[0] == '\0' && len >= 0)
		return ((char *)haystack);
	while (haystack[c1] && c1 < len)
	{
		c2 = 0;
		while (needle[c2] && (c1 + c2) < len && haystack[c1 + c2] == needle[c2])
			++c2;
		if (needle[c2] == 0)
			return ((char *)(haystack + c1));
		++c1;
	}
	return (NULL);
}

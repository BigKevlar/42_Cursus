/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:19:57 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/15 14:38:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
haystack = pajar
needle = aguja
tenemos que avanzar con dos blucles y dos contadores!!!!
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	cont;

	cont = 0;
	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen(needle) > ft_strlen(haystack))
		return (0);
	while (needle[cont] != '\0' && cont < len)
	{
		if (needle[cont] == haystack[cont])
			return ((char *)haystack);
		cont++;
	}
	return (0);
}

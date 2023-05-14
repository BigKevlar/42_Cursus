/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:44:54 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/14 19:39:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
RECORDAR QUE UN SIZE_T NO PUEDE SER NULL, PODRIA SER 0. VOID SI PUEDE SER NULL.
...(completar descripcion de la funcion)...
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cont;
	const char	*s1;

	cont = 0;
	c = (char)c;
	s1 = (const char *)s;
	if (n == 0)
		return (NULL);
	while (cont < n)
	{
		if (s1[cont] == c)
			return ((void *)&(s1[cont]));
		cont++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:17:30 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/15 11:41:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(descripcion de la funcion)
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ss1;
	unsigned char	*ss2;
	size_t			cont;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	cont = 0;
	if (ss1 == NULL && ss2 == NULL)
		return (0);
	while (cont < n)
	{
		if (ss1[cont] != ss2[cont])
			return ((int)(ss1[cont] - ss2[cont]));
		cont++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:35:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Copia al final de "dst" "len" bytes de "src", asegurando superposicion. */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	cont;

	dst1 = (char *)dst;
	src1 = (char *)src;
	cont = 0;
	if (dst == NULL && src == NULL)
		return (0);
	if (dst1 > src1)
	{
		while (len-- > 0)
			dst1[len] = src1[len];
	}
	else
	{
		while (len > cont)
		{
			dst1[cont] = src1[cont];
			cont++;
		}
	}
	return (dst);
}
/*Recordar que "return (dst)" permite devolver el puntero al inicio.*/

/*
int	main(void)
{
	char src[42] = "Hakunamatata";
	char dst[sizeof(src)];

	printf("Contenido de 'dst' antes de ft_memmove: %s\n", dst);
	ft_memmove(dst, src, ft_strlen(src) + 1);
	printf("Contenido de 'dst' despues de ft_memmove: %s\n", dst);
	return (0);
}
*/
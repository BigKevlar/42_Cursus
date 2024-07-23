/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 13:51:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Copia al final de "dst" "n" bytes de "src", directamente. */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			cont;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	cont = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (n)
	{
		dst1[cont] = src1[cont];
		cont++;
		n--;
	}
	return (dst);
}
/*Recordar que "return (dst)" permite devolver el puntero al inicio.*/

/*
int	main(void)
{
	char src[42] = "Hakunamatata";
	char dst[sizeof(src)];

	printf("Contenido de 'dst' antes de ft_memcpy: %s\n", dst);
	ft_memcpy(dst, src, ft_strlen(src) + 1);
	printf("Contenido de 'dst' despues de ft_memcpy: %s\n", dst);
	return (0);
}
*/
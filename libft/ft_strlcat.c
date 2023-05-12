/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:48:12 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/12 14:20:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COPIA "src" EN OTRO "dst" ASEGURANDO EL TAMAÑO EN DESTINO...*/
/*..."dst_size" ACABADO EN NULO, Y DEVUELVE EL TAMAÑO DEL ARRAY DE ORIGEN.*/
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	cont;
	int		src_size;

	cont = 0;
	src_size = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dst_size != 0)
	{
		while (src[cont] != '\0' && cont < dst_size - 1)
		{
			dst[cont] = src[src_size];
			cont++;
			src_size++;
		}
		dst[cont] = '\0';
	}
	return (src_size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:48:12 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:27:33 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Copia la cadena "src" al final de "dst" asegurando que el tamaño "size"
no se desborde. */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	pos_dst;
	size_t	pos_src;

	pos_dst = 0;
	pos_src = 0;
	while (dst[pos_dst] && pos_dst < size)
		pos_dst++;
	while (src[pos_src] && (pos_dst + pos_src + 1) < size)
	{
		dst[pos_dst + pos_src] = src[pos_src];
		pos_src++;
	}
	if (pos_dst < size)
		dst[pos_dst + pos_src] = '\0';
	return (pos_dst + ft_strlen(src));
}
/*Las variables "dst" y "src" tendran sus propios contadores para ir
navegando entre sus posiciones. El primer bucle mueve la posicion de
destino hasta donde queremos empezar a copiar la cadena de origen.*/

/*
int main(void)
{
	const char	src[42] = "Hola, mundo!";
	char		dest[42];
	size_t		size = sizeof(dest);
	size_t		len;

	len = ft_strlcat(dest, src, size);
	printf("Cadena copiada: %s\n", dest);
	printf("Longitud de la cadena copiada: %zu\n", len);
	return (0);
}
*/

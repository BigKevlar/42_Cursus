/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:15:01 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:27:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Copia la cadena "src" en "dst" asegurando el tamaño "dst_size" y el nulo. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	cont;
	size_t	src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	cont = 0;
	if (dst_size != 0)
	{
		while (src[cont] != '\0' && cont < (dst_size - 1))
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = '\0';
	}
	return (src_size);
}

/*
int	main(void)
{
	const char	ori[42] = "Hakunamatata";
	char		dest[42];
	size_t		tam_dest = 3;
	size_t		long;
	
	long = ft_strlcpy(dest, ori, tam_dest);
	printf("Cadena copiada: %s\n", dest);
	printf("Número de caracteres copiados: %zu\n", long);
	return (0);
}
*/
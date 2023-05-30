/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:15:01 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/30 11:46:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Copia la cadena "src" en "dst" asegurando el tamaño "dst_size" y el nulo.#*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	cont;
	int		src_size;

	if (!dst || !src)
		return (0);
	cont = 0;
	src_size = ft_strlen(src);
	if (dst_size != 0)
	{
		while (src[cont] != '\0' && cont < dst_size - 1)
		{
			dst[cont] = src[cont];
			cont++;
		}
		dst[cont] = '\0';
	}
	return (cont);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:45:48 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Copia en "b" el caracter "c" en sus primeras "len" posiciones. */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			cont;

	str = (unsigned char *)b;
	cont = 0;
	while (len)
	{
		str[cont] = c;
		cont++;
		len--;
	}
	return (b);
}

/*En el main casteamos "char *" a "void *" para imprimir correctamente.*/
/*
int	main(void)
{
	char	*phr;

	phr = ft_memset("Hakunamatata", 'x', 6);
	printf("%p\n", (void *)phr);
	return (0);
}
*/
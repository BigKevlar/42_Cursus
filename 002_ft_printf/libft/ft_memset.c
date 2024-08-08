/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:45:48 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/31 12:00:06 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Copia el caracter "c" en las primeras "len" posiciones de "b".#*/
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
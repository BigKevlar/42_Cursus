/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:17:30 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:08 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Compara los primeros "n" bytes de "s1" y "s2" (en ASCII), y devuelve un
número negativo si "s1" es menor que "s2", un número positivo si "s1" es
mayor que "s2", o 0 si son iguales. Esta funcion es similar a ft_strncmp,
con la diferencia de que esta no esta solo limitada a strings (terminaria
si encontrase un NULL).#*/
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

/*
int	main(void)
{
	const char string1[42] = "World";
	const char string2[42] = "Hello";
	size_t n = 10;
	int result = ft_memcmp(string1, string2, n);

	if (result < 0)
		printf("'%s' es menor que '%s'.\n", string1, string2);
	else if (result > 0)
		printf("'%s' es mayor que '%s'.\n", string1, string2);
	else
		printf("'%s' es igual a '%s'.\n", string1, string2);
	return 0;
}
*/
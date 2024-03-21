/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:27:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Busca en la cadena "s" el primer caracter "c". */
char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	c1;
	size_t	cont;

	s1 = (char *)s;
	c1 = (char)c;
	cont = 0;
	while (s1[cont] != '\0')
	{
		if (s1[cont] == c1)
			return (&s1[cont]);
		cont++;
	}
	if (c1 == '\0')
		return (&s1[cont]);
	return (NULL);
}

/*
int	main(void)
{
	char	x[42] = "Hakunamatata";
	char	c = 't';
	char	*result = ft_strchr(x, c);

	printf("La cadena es '%s' y el caracter buscado es '%c'.\n", x, c);
	printf("Se encontro el caracter a partir de '%s'.\n", result);
	return (0);
}
*/
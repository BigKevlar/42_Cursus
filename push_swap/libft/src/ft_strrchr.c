/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:36:37 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

/* Busca en la cadena "s" el ultimo caractero "c". */
char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	c1;
	int		cont;

	s1 = (char *)s;
	c1 = (char)c;
	cont = 0;
	while (s1[cont] != '\0')
		cont++;
	while (cont >= 0)
	{
		if (s1[cont] == c1)
			return (s1 + cont);
		cont--;
	}
	return (0);
}

/*
int	main(void)
{
	char	*phrase = "Hakunamatata";
	int		c = 't';
	printf("%s, %c, %s.\n", phrase, c, ft_strrchr(phrase, c));
	return (0);
}
*/
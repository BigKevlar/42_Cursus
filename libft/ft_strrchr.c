/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:36:37 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/30 12:58:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Busca el ultimo caracter "c" dentro de una cadena "s".#*/
char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	char	c1;
	size_t	cont;

	s1 = (char *)s;
	c1 = (char)c;
	cont = ft_strlen(s1);
	while (cont != 0)
	{
		if (s1[cont] == c1)
			return (s1 + cont);
		cont--;
	}
	return (NULL);
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
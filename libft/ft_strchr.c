/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:27 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/09 15:33:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION BUSCA UNA LETRA "C" DENTRO DE UN STRING "S".*/
char	*ft_strchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s;
	c = (char)c;
	while (*s1 != c)
	{
		if (*s1 == '\0')
			return (NULL);
		s1++;
	}
	return (s1);
}

/*
int	main(void)
{
	char	x[10] = "teste";
	char	c = '\0';

	printf("%s", ft_strchr(x, c));
	return (0);
}
*/

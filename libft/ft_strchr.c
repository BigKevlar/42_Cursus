/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 11:31:27 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/02 14:14:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION BUSCA UNA LETRA "C" DENTRO DE UN STRING "S".*/
char	*ft_strchr(const char *s, int c)
{
	char	*x;

	x = ((char *)s);
	while (*x != c)
	{
		if (*x == '\0')
			return (NULL);
		x++;
	}
	return (x);
}

int	main(void)
{
	char	x[10] = "teste";
	char	c = '\0';

	printf("%s", ft_strchr(x, c));
	return (0);
}

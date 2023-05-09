/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:36:37 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/09 15:09:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION BUSCA EL ULTIMO CARACTER "c" DE DE UN STRING "s".*/
char	*ft_strrchr(const char *s, int c)
{
	int		cont;
	char	*string;

	string = (char *)s;
	cont = ft_strlen(string);
	c = (char)c;
	while (cont >= 0)
	{
		if (string[cont] == c)
			return (string + cont);
		cont--;
	}
	return (0);
}
/*NOTA: EL PRIMER BUCLE SE PODRIA SUSTITUIR CON "ft_strlen - 1".*/
/*
int	main(void)
{
	printf("%s", ft_strrchr("hola", 'u'));
	return (0);
}
*/

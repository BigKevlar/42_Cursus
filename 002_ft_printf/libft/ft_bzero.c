/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:49:31 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/31 12:10:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Copia el numero 0 en las primeras "n" posiciones de "s".#*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			cont;

	str = (unsigned char *)s;
	cont = 0;
	if (n == 0)
		return ;
	while (n > cont)
	{
		str[cont] = '\0';
		cont++;
	}
	return ;
}

/*
int	main(void)
{
	char	phr[] = "Hakunamatata";

	ft_bzero(phr, 6);
	printf("%s\n", phr);
	return (0);
}
*/
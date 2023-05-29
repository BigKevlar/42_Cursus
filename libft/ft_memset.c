/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:45:48 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/28 18:18:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Copia el caracter "c" en las primeras "len" posiciones de "b".#*/
void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = (char *)b;
	while (len)
	{
		*str = c;
		len--;
		str++;
	}
	return (b);
}

/*
int	main(void)
{
	char	string[] = "Hakunamatata";
	char	character = 'x';

	ft_memset(string, character, 6);
	printf("%s\n", string);
	return (0);
}
*/
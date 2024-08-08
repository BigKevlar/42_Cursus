/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:02:48 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/28 17:33:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Devuelve a longuitud de una cadena/string.#*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
int	main(void)
{
	size_t	str;

	str = ft_strlen("Hakunamatata");
	printf("La cadena/string tiene %zu caracteres.\n", str);
	return (0);
}
*/
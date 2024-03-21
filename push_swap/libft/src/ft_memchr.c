/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:44:54 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:05 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Busca el caracter "c" en los primeros "n" bytes de "s".
Si se encuentra el caracter la función devuelve un puntero al contenido
donde se encontró. Si no, la función devuelve NULL.#*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	cont;
	char	*s1;

	cont = 0;
	s1 = (char *)s;
	while (cont < n)
	{
		if (s1[cont] == (char)c)
			return ((void *)&(s1[cont]));
		cont++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	string[42] = "Hakunamatata";
	int			word = 't';
	size_t		len = 10;
	void		*result = ft_memchr(string, word, len);

	if (result != NULL)
		printf("'%c' en la posición %ld.\n", word, (char *)result - string);
	else
		printf("'%c' no se encontró en los primeros %zu bytes.\n", word, len);
	return 0;
}
*/
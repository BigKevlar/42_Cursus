/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:44:54 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/30 14:05:34 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Busca el caracter "c" en los primeros "n" bytes de "s".
Si se encuentra el caracter la función devuelve un puntero al contenido
donde se encontró. Si no, la función devuelve NULL.#*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cont;
	const char	*s1;

	cont = 0;
	s1 = (const char *)s;
	if (n == 0)
		return (NULL);
	while (cont < n)
	{
		if (s1[cont] == c)
			return ((void *)&(s1[cont]));
		cont++;
	}
	return (NULL);
}
/*Ojo, un size_t no puede ser NULL, puede ser 0. Sin embargo void si puede.*/

/*
int	main(void)
{
	const char string[42] = "Hakunamatata";
	int word = 't';
	size_t len = 10;
	void *result = ft_memchr(string, word, len);

	if (result != NULL)
		printf("Se encontró el carácter '%c' en la posición %ld.\n", word, (char *)result - string);
	else
		printf("El carácter '%c' no se encontró en los primeros %zu bytes.\n", word, len);
	return 0;
}
*/
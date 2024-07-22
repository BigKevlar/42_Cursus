/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:19:57 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Busca la cadena "neddle" (aguja) en la cadena "haystack" (pajar) durante
un maximo de "len" posiciones. Se va avanzando con dos bucles/contadores.#*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cont1;
	size_t	cont2;
	char	*haystack1;
	char	*needle1;

	cont1 = 0;
	cont2 = 0;
	haystack1 = (char *)haystack;
	needle1 = (char *)needle;
	if (needle1[0] == '\0')
		return (haystack1);
	while (haystack1[cont1] && cont1 < len)
	{
		cont2 = 0;
		while (needle1[cont2] && (cont1 + cont2) < len
			&& haystack1[cont1 + cont2] == needle1[cont2])
			++cont2;
		if (needle1[cont2] == 0)
			return ((haystack1 + cont1));
		++cont1;
	}
	return (NULL);
}

/*
int main(void)
{
	char	haystack[42] = "Timon y Pumba";
	char	needle[42] = "Pum";
	size_t	len = 16;
	char	*result = ft_strnstr(haystack, needle, len);
	
	if (result != NULL)
		printf("La subcadena '%s' encontrada en '%s'\n", needle, haystack);
	else
		printf("La subcadena '%s' no se encontró en '%s'\n", needle, haystack);
	return 0;
}
*/
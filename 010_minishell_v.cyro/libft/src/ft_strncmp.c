/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:25:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:28:05 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Compara los primeros "n" caracteres de "s1" y "s2", va restando
sus valores (en ASCII) hasta que, o termina una de las dos cadenas
o cuando se alcanza numero de caracteres deseados a comparar.
Si hay diferencia entre caracteres devuelve la resta en "unsigned char"
para evitar problemas con los simbolos negativos, y sale de la funcion.
Si no se encuentra nada se devuelve "0", que indica que son iguales.#*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while ((s1[cont] || s2[cont]) && cont < n)
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
	}
	return (0);
}

/*
int	main(void)
{
	const char string1[42] = "Hakuna";
	const char string2[42] = "matata";
	size_t len = 4;
	int result = ft_strncmp(string1, string2, len);

	if (result < 0)
		printf("'%s' es menor que '%s' en los primeros %zu caracteres.\n", 
		|| string1, string2, len);
	else if (result > 0)
		printf("'%s' es mayor que '%s' en los primeros %zu caracteres.\n", 
		|| string1, string2, len);
	else
		printf("'%s' es igual a '%s' en los primeros %zu caracteres.\n", 
		|| string1, string2, len);
	return (0);
}
*/
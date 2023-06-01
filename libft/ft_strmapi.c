/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:14:45 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/01 18:05:13 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Ejecuta una funcion "f" dada a cada caracter de una cadena de caracteres y
devuelve una nueva cadena con los resultados de esa funcion.#*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		cont;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	cont = 0;
	while (s[cont])
	{
		str[cont] = f(cont, s[cont]);
		++cont;
	}
	str[cont] = '\0';
	return (str);
}
/*Que utilidad podria tener esta funcion???*/

/*(...main en desarrollo...)*/
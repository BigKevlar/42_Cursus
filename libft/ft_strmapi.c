/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:14:45 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/21 19:26:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
(a partir de estas funciones vamos a empezar a declarar los valores
de las variables antes de la parte en la que van a usarse, por claridad)
*/
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

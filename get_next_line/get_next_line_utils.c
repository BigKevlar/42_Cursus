/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:01:20 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/14 20:01:31 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* AQUI PONDREMOS FUNCIONES EXTERNAS, YA QUE NO SE PUEDE USAR "LIBFT". */

/* Funcion externa: Busca dentro del string "s" el caracter "c". */
char	*ft_strchr(char *s, int c)
{
	int		cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == c)
			return ((char *)&s[cont]);
		cont++;
	}
	return (0);
}

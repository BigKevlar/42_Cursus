/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:18:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/22 13:13:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
A cada carácter de la string "s", aplica la función "f" dando como
parámetros el índice de cada carácter dentro de "s" y la dirección
del propio carácter, que podrá modificarse si es necesario.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:59 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:41 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime una cadena de caracteres (%s). */
int	ft_printing_string(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(s, 1);
	while (s[len])
		len++;
	return (len);
}

/* DESARROLLO */
/*
Empezamos definiendo la vaiable "len" en 0, y ponemos una condicion de
seguridad por si no pasasemos nada por parametros escriba "(null)" y
devuelva 6, que es el numero de posiciones de la palabra. Si hubiera
un input hacemos que lo imprima por consola con nuestra funcion de
libft "ft_putstr_fd", que imprime strings o cadenas. Luego un bucle
va iterando por el string y cuenta las posiciones y las retorna.
*/
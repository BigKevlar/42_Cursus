/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:59 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/19 16:06:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

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
	while (s[len])
		len++;
	ft_putstr_fd(s, 1);
	return (len);
}

/* DESARROLLO */
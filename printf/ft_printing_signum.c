/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_signum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:28 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/19 16:06:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Imprime numeros enteros con signo (%d %i). */
int	ft_printing_signum(int n)
{
	int	len;
	int	n_aux;

	len = 0;
	n_aux = n;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		len++;
		n_aux = n_aux * -1;
	}
	while (n_aux > 0)
	{
		len++;
		n_aux = n_aux / 10;
	}
	ft_putnbr_fd(n, 1);
	return (len);
}

/* DESARROLLO */
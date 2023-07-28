/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_signum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:28 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/27 18:45:01 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime numeros enteros con signo (%d %i). */
int	ft_printing_signum(int n)
{
	int	len;

	len = 0;
	ft_putnbr_fd(n, 1);
	if (n < 0 && n > -2147483648)
	{
		n = n * -1;
		len++;
	}
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/* DESARROLLO */
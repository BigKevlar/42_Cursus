/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_unsignum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:14:30 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/27 16:09:30 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime numeros enteros sin signo (%u). */
void	ft_putnbr_unsigned(unsigned int n, int fd)
{
	char	chr;

	if (n >= 10)
	{
		ft_putnbr_unsigned(n / 10, fd);
		chr = '0' + n % 10;
	}
	else
		chr = '0' + n;
	write(fd, &chr, 1);
}

int	ft_printing_unsignum(unsigned int n)
{
	int	len;

	len = 0;
	ft_putnbr_unsigned(n, 1);
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

/* DESARROLLO */
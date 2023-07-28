/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_unsignum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:14:30 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/28 17:50:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime numeros enteros sin signo (%u). */
/*
void	ft_putnbr_unsigned(unsigned int n)
{
	int	aux;

	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		aux = n % 10 + '0';
	}
	else
		aux = n + '0';
	write(1, &aux, 1);
}
*/

void	ft_putnbr_unsigned(unsigned int n)
{
	int	aux;

	while (n > 0)
	{
		aux = n % 10 + '0';
		n = n / 10;
		write(1, &aux, 1);
	}
}

int	ft_printing_unsignum(unsigned int n)
{
	int	len;

	len = 0;
	ft_putnbr_unsigned(n);
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/* DESARROLLO */
/*
Muy similar a la funcion con signo. Lo primero que tenemos es una version
custom de nuestra funcion de libreria "ft_putnbr_fd", a la que llamaremos
"ft_putnbr_unsigned", la cual tendra un valor tipo int y: si "n" es mayor
que 9 se llamara recursivamente imprimiendo los digitos
*/
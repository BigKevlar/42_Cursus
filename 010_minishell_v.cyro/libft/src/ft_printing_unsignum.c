/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_unsignum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:14:30 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime numeros enteros sin signo (%u). */
void	ft_putnbr_unsigned(unsigned int n)
{
	char	aux;

	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		aux = n % 10 + '0';
	}
	else
		aux = n + '0';
	write(1, &aux, 1);
}

int	ft_printing_unsignum(unsigned int n)
{
	int	len;

	len = 0;
	ft_putnbr_unsigned(n);
	if (n == 0)
		return (1);
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

/* DESARROLLO */
/*
Muy similar a la funcion con signo. Lo primero que tenemos es una version
simple de nuestra funcion de libreria "ft_putnbr_fd" a la que llamaremos
"ft_putnbr_unsigned", la cual tendra un valor tipo int y: si "n" es mayor
que 9 se llamara recursivamente imprimiendo los digitos.
Ahora bien, la funcion principal hara lo siguiente:
- Declaramos la variable int "len" en valor 0.
- Imprimimos el numero con la subfuncion de antes.
- Vamos iterando con "n" y sumando uno a "len".
- Sumamos un ultimo valor a "len" para contar el ultimo valor que no
cuenta el bucle.
- Devolvemos "len".
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_signum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:28 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

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
/*
Nuestra funcion empieza declarando "len" valor 0 para ir contando, e
imprimimos directamente el numero para no variar valor de "n". Tener
en cuenta que nuestra funcion de libreria "ft_putnbr_fd" ya se encarga
de poner el signo "-" , asi que no lo implementamos aqui.
- Si "n" es menor que 0 o mayor que el menor numero que podemos alcanzar
con un int, le cambiamos de negativo a positivo y contamos uno a "len"
para contar el signo.
- Si es 0, devolvemos 1.
- Si es el numero mas pequeño negativo, devolvemos 11.
En cualquier otro caso con un bucle recorremos todas las posiciones y
vamos sumando 1 a "len", devolviendolo al final.
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:47 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:34 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime la direccion de un puntero "void *" en valor hexadecimal (%p). */
int	pointer_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	pointer_print(uintptr_t n)
{
	if (n >= 16)
	{
		pointer_print(n / 16);
		pointer_print(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_printing_pointer(unsigned long p)
{
	int	p_size;

	p_size = 2;
	write(1, "0x", 2);
	if (p == 0)
		p_size = p_size + write(1, "0", 1);
	else
	{
		p_size = p_size + pointer_len(p);
		pointer_print(p);
	}
	return (p_size);
}

/* DESARROLLO */
/* 
Primero las subfunciones:
*/
/*
"pointer_len" cuenta la longitud de la direccion de memoria en su
formato hexadecimal dividiendo el numero repetidamente entre 16
mientras que "n" no sea 0, y aumenta "len".
*/
/*
"pointer_print" imprime la direccion en hexadecimal, tomando
el resto y modulo de la division entre 16.
- Si es menor o igual a 9 significa que es un numero decimal del 0 al 9,
asi que lo imprime pero pasandolo a ASCII sumandole '0'.
- Si es mayor que 9 significa que es una letra de la A ('10') a la
F ('15'), por lo que a "n" le quitamos 10 y sumamos "a" para que nos
imprima un valor de la 'a' a la 'f'. Ojo, el tipado es
"void" porque no tiene que retornar nada, solo imprimir.
*/
/*
Por ultimo la funcion principal: se inicia declarando una variable int
con valor 2, porque todas las direcciones de memoria empiezan por "0x",
y lo imprime por pantalla. Luego controla que si es 0 pues se sume un valor
a "p_size", se imprima un 0 y se retorne esos 2 del principio mas uno mas.
Si no es 0 primero cuenta y suma las posiciones de la direccion, y luego
la imprime. Devuelve al final las posiciones contadas.
*/
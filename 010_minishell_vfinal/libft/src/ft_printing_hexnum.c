/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_hexnum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:15:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime numeros en base hexadecimal en minusculas (%x) o mayusculas (%X). */
int	hexnum_len(unsigned int n)
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

void	hexnum_print(uintptr_t n, char type)
{
	if (n >= 16)
	{
		hexnum_print(n / 16, type);
		hexnum_print(n % 16, type);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			else if (type == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printing_hexnum(unsigned int n, char type)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		hexnum_print(n, type);
	return (hexnum_len(n));
}

/* DESARROLLO */
/*
Al igual que en la subfuncion de la funcion anterior, "hexnum_len" la
usamos contar la longitud del numero hexadecimal dividiendo el numero
repetidamente entre 16 mientras que "n" no sea 0, y aumentando "len".
*/
/*
Tambien igual que en la anterior, tenemos una funcion ahora llamada 
"hexnum_print"mediante la que imprimiremos el numero teniendo en
cuenta (despues de llamarse recursivamente y teniendo en cuenta
su dividendo y modulo):
- Si es menor o igual que 9 significa que es un numero decimal entre
el 0 y 9, por lo que imprime el numero sumandole '0' para obtener su
valor en ASCII.
- Si no lo es hace una de dos: si es minuscula el caracter le quitamos
10 y sumamos 'a' para que nos imprima un valor en minuscula. Si es
mayuscula todo lo contrario, le sumamos 10 y 'A' para que nos imprima
un valor en mayuscula.
*/
/*
Ahora en la funcion principal: si el numero es '0' lo imprimimos y
devolvemos 1. Si no llamamos a "hexnum_print" para imprimir el numero
en hexadecimal ya sea en minisculas o mayusculas dependiendo
del tipo "type" que le pasemos. Y por ultimo devuelve la longuitud
directamente con "hexnum_len".
*/
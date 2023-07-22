/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:47 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/22 16:53:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* funcion PRINTF CUSTOM "jmartos-" */

/* Imprime la direccion de un puntero "void *" en valor hexadecimal (%p). */
/* uintptr_t => tipado para direcciones de memoria (ver libreria de C). */
/* Subfuncion que cuenta la longitud de la direccion de memoria en su
formato hexadecimal. */
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

/* Subfuncion que imprime la direccion en hexadecimal. OJO: el tipado es
"void" porque no tiene que retornar nada, solo imprimir. */
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
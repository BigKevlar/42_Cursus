/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:09:47 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/19 16:55:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Imprime la direccion de un puntero "void *" en valor hexadecimal (%p). */
/* uintptr_t => tipado para direcciones de memoria. */
/* Subfuncion que cuenta la longitud de la direccion de memoria. */
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

/* Subfuncion que imprime la direccion en hexadecimal. OJO: el tipo "void"
porque no tiene que retornar nada, solo imprimir. */
void	pointer_print(uintptr_t n)
{
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_put_ptr(n % 16);
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
	int	ptr_len;

	ptr_len = 2;
	write(1, "0x", 2);
	if (p == 0)
		ptr_len = ptr_len + write(1, "0", 1);
	else
	{
		ptr_len = ptr_len + pointer_len(p);
		pointer_print(p);
	}
	return (ptr_len);
}

/* DESARROLLO */
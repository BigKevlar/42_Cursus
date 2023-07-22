/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_hexnum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:15:50 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/22 16:44:41 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* funcion PRINTF CUSTOM "jmartos-" */

/* Imprime numeros en base hexadecimal en minusculas (%x) o mayusculas (%X). */
/* Subfuncion que cuenta la longitud del numero hexadecimal. */
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

/* Subfuncion que imprime la direccion en hexadecimal. OJO: el tipado es
"void" porque no tiene que retornar nada, solo imprimir. */
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
		return (write(1, "0", 1));
	else
		hexnum_print(n, type);
	return (hexnum_len(n));
}

/* DESARROLLO */
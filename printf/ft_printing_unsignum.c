/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_unsignum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:14:30 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/24 16:25:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* funcion PRINTF CUSTOM "jmartos-" */

/* Imprime numeros enteros sin signo (%u). */
int	ft_printing_unsignum(unsigned int n)
{
	int	len;

	len = 1;
	ft_putnbr_fd(n, 1);
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

/* DESARROLLO */
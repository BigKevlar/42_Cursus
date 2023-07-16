/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_signum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:28 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/16 22:45:00 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/* Imprime numeros enteros con signo (%d %i). */
int	ft_printing_signum(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		len++;
	}
	else if (n > 0)
	{
		ft_putchar_fd('+', 1);
		len++;
	}
	len = len + ft_putnbr_fd(n, 1);
	return (len);
}

/* DESARROLLO */
/*  */
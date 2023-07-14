/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_signum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:12:28 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/14 18:30:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/* Imprime numeros enteros con signo (%d %i). */
int	ft_printing_signum(int n)
{
	if (n == '\0')
	{
		ft_putstr_fd("ERROR", 1);
		return (5);
	}
	ft_putnbr_fd(n, 1);
	return (n);
}

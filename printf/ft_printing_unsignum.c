/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_unsignum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:14:30 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/13 16:51:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft/libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/* Imprime numeros enteros sin signo (%u). */
int ft_printing_unsignum(int n)
{
    int	len;

	len = 0;
	if (n == '\0')
	{
		ft_putstr_fd("ERROR", 1);
		return (5);
	}
    /*sirve para imprimir un solo numero como el printing_char, o varios???*/
}
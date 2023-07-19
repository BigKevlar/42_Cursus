/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:09 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/19 15:31:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /*funcion printf CUSTOM "jmartos-"*/

/* Imprime un solo caracter o simbolo (%c, %%). */
int	ft_printing_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

/* DESARROLLO */
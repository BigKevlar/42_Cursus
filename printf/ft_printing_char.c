/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:09 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/22 14:09:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* funcion PRINTF CUSTOM "jmartos-" */

/* Imprime un solo caracter o simbolo (%c, %%). */
int	ft_printing_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/* DESARROLLO */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:09 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/27 17:13:21 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime un solo caracter o simbolo (%c, %%). */
int	ft_printing_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/* DESARROLLO */
/*
Devuelve 1 e imprime por pantalla un unico caracter/simbolo/numero.
*/
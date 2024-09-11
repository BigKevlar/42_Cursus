/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:09:09 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/17 17:21:01 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h" /* Funcion printf CUSTOM "jmartos-". */

/* Imprime un solo caracter o simbolo (%c, %%). */
int	ft_printing_char(int c)
{
	write(1, &c, 1);
	return (1);
}

/* DESARROLLO */
/*
Devuelve e imprime por pantalla un unico caracter/simbolo/numero.
*/
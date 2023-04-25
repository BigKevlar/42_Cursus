/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:14:49 by kevlar            #+#    #+#             */
/*   Updated: 2023/04/24 17:20:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ctype.h> /*LIBRERIA DE TODAS LAS FUNCIONES TIPO IS.*/
#include	<stdio.h> /*LIBRERIA PARA EL PRINTF DEL MAIN.*/
/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES ALFANUMERICO.*/
int	ft_isascii.c(int x)
{
	if ((x >= 0 && x <= 31) || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	x;

	x = 'h';
	printf("%d",ft_isalnum(x));
	return (0);
}
*/
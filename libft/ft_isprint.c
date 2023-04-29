/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:00:08 by jmartos-          #+#    #+#             */
/*   Updated: 2023/04/29 15:16:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ctype.h> /*LIBRERIA DE TODAS LAS FUNCIONES TIPO IS.*/
#include	<stdio.h> /*LIBRERIA PARA EL PRINTF DEL MAIN.*/

/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES IMPRIMIBLE (VER TABLA ASCII).*/
int	ft_isascii(int x)
{
	if ((x >= 32 && x <= 126))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	x;

	x = '@';
	printf("%d",ft_isalnum(x));
	return (0);
}
*/
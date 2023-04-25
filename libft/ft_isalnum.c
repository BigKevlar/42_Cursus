/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:01:48 by kevlar            #+#    #+#             */
/*   Updated: 2023/04/25 13:14:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<ctype.h> /*LIBRERIA DE TODAS LAS FUNCIONES TIPO IS.*/
#include	<stdio.h> /*LIBRERIA PARA EL PRINTF DEL MAIN.*/

/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES ALFANUMERICO.*/
int	ft_isalnum(int x)
{
	if ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z')
		|| (x >= 'A' && x <= 'Z'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	x;

	x = 'h';
	printf("%d",ft_isalnum(x));s
	return (0);
}
*/
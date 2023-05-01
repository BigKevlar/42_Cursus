/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:02:48 by jmartos-          #+#    #+#             */
/*   Updated: 2023/04/29 16:36:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<string.h> /*LIBRERIA PARA OEPRACIONES DE MEMORIA*/
#include	<stdio.h> /*LIBRERIA PARA EL PRINTF DEL MAIN.*/

/*ESTA FUNCION DEVUELVE LA LONGUITUD DE UN STRING.*/
int	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		n = n + 1;
	}
	return (n);
}

/*
int main ()
{
	int phrase;

	phrase = ft_strlen("pepito");
	printf("Este string tiene %d caracteres.", phrase);
	return (0);
}
*/

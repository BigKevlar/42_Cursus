/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:00:08 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/01 15:07:48 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES IMPRIMIBLE (VER TABLA ASCII).*/
int	ft_isprint(int x)
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
	printf("%d",ft_isprint(x));
	return (0);
}
*/
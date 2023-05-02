/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:14:49 by kevlar            #+#    #+#             */
/*   Updated: 2023/05/02 11:23:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES UN CARACTER ASCII.*/
int	ft_isascii(int x)
{
	if ((x >= 0 && x <= 127))
		return (1);
	return (0);
}

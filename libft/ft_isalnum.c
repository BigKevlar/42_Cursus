/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:01:48 by kevlar            #+#    #+#             */
/*   Updated: 2023/05/02 11:23:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES ALFANUMERICO.*/
int	ft_isalnum(int x)
{
	if ((x >= '0' && x <= '9') || (x >= 'a' && x <= 'z')
		|| (x >= 'A' && x <= 'Z'))
		return (1);
	return (0);
}

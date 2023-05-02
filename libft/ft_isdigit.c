/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:47:15 by kevlar            #+#    #+#             */
/*   Updated: 2023/05/02 11:23:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION COMPRUEBA SI UN CARACTER ES NUMERICO.*/
int	ft_isdigit(int x)
{
	if ((x >= '0' && x <= '9'))
		return (1);
	return (0);
}

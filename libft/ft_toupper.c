/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:16:25 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/01 18:50:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION CONVIERTE LAS MINUSCULAS EN MAYUSCULAS.*/
char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
		return (c);
	}
	else if (c >= 'A' && c <= 'Z')
		return (c);
	else
		return (0);
}

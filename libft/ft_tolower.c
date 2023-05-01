/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 18:53:18 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/01 18:58:33 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*ESTA FUNCION CONVIERTE LAS MAYUSCULAS EN MINUSCULAS.*/
char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		c += 32;
		return (c);
	}
	else if (c >= 'a' && c <= 'z')
		return (c);
	else
		return (0);
}

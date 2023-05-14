/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:25:31 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/14 18:43:28 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
ESTA FUNCION COMPARA CARACTER POR CARACTER LAS CADENAS "s1" Y "s2",
VA RESTANDO SUS VALORES (EN ASCII) HASTA QUE, O TERMINA UNA DE LAS DOS CADENAS
O CUANDO SE ALCANZA NUMERO DE CARACTERES DESEADOS A COMPARAR "n".
SI HAY DIFERENCIA ENTRE CARACTERES DEVUELVE LA RESTA EN "unsigned char",
PARA EVITAR PROBLEMAS CON LOS SIMBOLOS NEGATIVOS, Y SALE DE LA FUNCION. SI
NO SE ENCUENTRA NADA SE DEVUELVE "0", QUE INDICA QUE SON IGUALES.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while ((s1[cont] || s2[cont]) && cont < n)
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
	}
	return (0);
}

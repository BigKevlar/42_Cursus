/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:00:08 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/28 16:35:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Comprueba si "x" es un caracter imprimible de la tabla ASCII.#*/
int	ft_isprint(int x)
{
	if ((x >= 32 && x <= 126))
		return (1);
	return (0);
}

/*
int	main(void)
{
	if (ft_isprint('@'))
		printf("El caracter SI es un caracter imprimible.\n")
	else
		printf("El caracter NO es un caracter imprimible.\n")
	return (0);
}
*/
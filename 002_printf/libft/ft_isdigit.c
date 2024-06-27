/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:47:15 by kevlar            #+#    #+#             */
/*   Updated: 2023/05/24 14:46:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Comprueba si un caracter "x" es numerico.#*/
int	ft_isdigit(int x)
{
	if (x >= '0' && x <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	if (ft_isdigit('7'))
		printf("El caracter SI es numerico.\n");
	else
		printf("El caracter NO es numerico.\n");
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:14:49 by kevlar            #+#    #+#             */
/*   Updated: 2023/08/31 14:15:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /* Libreria 42 "jmartos-". */

/* Comprueba si un caracter "x" esta representado en la tabla ASCII. */
int	ft_isascii(int x)
{
	if (x >= 0 && x <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	if (ft_isascii('?'))
		printf("El caracter SI esta en la tabla ASCII.\n");
	else
		printf("El caracter NO esta en la tabla ASCII.\n");
	return (0);
}
*/
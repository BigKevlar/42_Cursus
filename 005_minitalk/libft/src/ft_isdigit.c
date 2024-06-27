/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:47:15 by kevlar            #+#    #+#             */
/*   Updated: 2023/08/31 14:13:59 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /* Libreria 42 "jmartos-". */

/* Comprueba si un caracter "x" es numerico. */
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
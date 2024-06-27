/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:10:52 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/24 14:34:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Comprueba si un caracter "x" es alfabetico.#*/
int	ft_isalpha(int x)
{
	if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
		return (1);
	return (0);
}

/*
int	main(void)
{
	if (ft_isalpha('h'))
		printf("El caracter SI es alfabetico.\n");
	else
		printf("El caracter NO es alfabetico.\n");
	return (0);
}
*/
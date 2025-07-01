/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:46 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:24:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Reserva memoria y crea una matriz con "count" elementos y de
tamaño "size" cada uno. Utilizamos la funcion ft_bzero para asegurarnos
que todas las posiciones estan inicializadas correctamente (no como malloc).#*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*array;

	array = malloc(count * size);
	if (!array)
		return (NULL);
	ft_bzero(array, count * size);
	return (array);
}

/*Este ejemplo reserva memoria para un array de 5 elementos de tipo int*/
/*
int	main(void)
{
	size_t	count = 5;
	size_t	size = sizeof(int);
	int		*array = (int *)ft_calloc(count, size);

	array[0] = 42;
	printf("%d\n", array[0]);
	free(array);
	return (0);
}
*/
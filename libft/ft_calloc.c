/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:16:46 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/16 15:14:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
SIRVE PARA RESERVAR MEMORIA Y CREAR UNA MATRIZ "count" DE TAMAÑO "size" CADA UNA.
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, count * size);
	return (pointer);
}
/*
int	main(void)
{
	int	size = 8539;

	void *d1 = ft_calloc(size, sizeof(int));
	void *d2 = calloc(size, sizeof(int));
	if (memcmp(d1, d2, size * sizeof(int)))
		exit(printf("TEST_FAILED"));
	free(d1);
	free(d2);
	exit(printf("TEST_SUCCESS"));
}
*/

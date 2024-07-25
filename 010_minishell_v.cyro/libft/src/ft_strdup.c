/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:15:51 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/09 22:48:46 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Duplica una cadena pasada como un puntero "s1" y devulve un puntero a un
nuevo puntero que contiene dicha copia.#*/
char	*ft_strdup(const char *s1)
{
	char	*new_array;
	int		len;

	len = ft_strlen(s1) + 1;
	new_array = malloc(len);
	if (!new_array)
		return (NULL);
	ft_strlcpy(new_array, s1, len);
	new_array[len - 1] = '\0';
	return (new_array);
}

/*
int	main(void)
{
	char	*ori = "Hakunamatata";
	char	*cpy;

	cpy = ft_strdup(ori);
	printf("%s\n", cpy);
	printf("END\n");
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:37:38 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/24 22:12:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

char	**ft_strd_new(char *str)
{
	char	**new_array;

	new_array = (char **)malloc(sizeof(char *) * 2);
	if (!new_array)
		return (NULL);
	new_array[0] = ft_strdup(str);
	if (!new_array[0])
	{
		free(new_array);
		return (NULL);
	}
	new_array[1] = NULL;
	return (new_array);
}

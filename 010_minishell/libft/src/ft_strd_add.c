/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:58:01 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/24 22:07:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

char	**ft_strd_add(char **array, char *str)
{
	int		i;
	char	**new_array;

	i = 0;
	while (array[i] != NULL)
		i++;
	new_array = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_array)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		new_array[i] = array[i];
		i++;
	}
	new_array[i] = strdup(str);
	if (!new_array[i])
	{
		free(new_array);
		return (NULL);
	}
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}

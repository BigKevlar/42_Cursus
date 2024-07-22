/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:22:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/18 21:35:47 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

static void ft_matrix_free(char **str)
{
    int c;
    
    c = 0;
    while (str[c])
    {
        free(str[c]);
        c++;
    }
    free(str);
}

char	**ft_matrixdup(char **matrix)
{
	char	**new;
	int		c;

    c = 0;
    if (matrix == NULL)
        return (NULL);
    while (matrix[c])
	    c++;
	new = (char **)malloc(sizeof(char *) * (c + 1));
	if (!new)
		return (NULL);
    c = 0;
	while (matrix[c])
	{
		new[c] = ft_strdup(matrix[c]);
		if (!new[c])
		{
			ft_matrix_free(new);
			return (NULL);
		}
		c++;
	}
	new[c] = NULL;
	return (new);
}
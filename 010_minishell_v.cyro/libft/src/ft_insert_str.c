/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:40:57 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 02:01:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

char	*ft_insert_str(char *main, char *piece, size_t pos)
{
	char	*new;
	size_t	new_pos;
	size_t	piece_pos;

	new = ft_calloc(sizeof(char), ft_strlen(main) + ft_strlen(piece) + 1);
	new_pos = 0;
	piece_pos = 0;
	while (new_pos < pos)
	{
		new[new_pos] = main[new_pos];
		new_pos++;
	}
	while (piece[piece_pos])
	{
		new[new_pos] = piece[piece_pos];
		new_pos++;
		piece_pos++;
	}
	while (main[pos])
	{
		new[new_pos] = main[pos];
		new_pos++;
		pos++;
	}
	return (new[new_pos] = '\0', new);
}

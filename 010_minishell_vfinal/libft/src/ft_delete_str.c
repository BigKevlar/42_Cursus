/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:40:57 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 02:04:23 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

char	*ft_delete_str(char *main, size_t start, size_t finish)
{
	size_t	main_pos;
	size_t	len;
	size_t	new_len;
	char	*new;
	size_t	new_pos;

	len = ft_strlen(main);
	new_len = len - (finish - start + 1);
	new = ft_calloc(sizeof(char), new_len + 1);
	if (!new)
		return (NULL);
	main_pos = 0;
	new_pos = 0;
	while (main_pos < start)
		new[new_pos++] = main[main_pos++];
	main_pos = finish + 1;
	while (main_pos < len)
		new[new_pos++] = main[main_pos++];
	free(main);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 23:40:57 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 00:09:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

char *ft_delete_str(char *main, size_t start, size_t finish)
{
	size_t main_pos = 0;
	size_t len = ft_strlen(main);
	size_t new_len = len - (finish - start + 1);
	char *new = ft_calloc(sizeof(char), new_len + 1);
	size_t new_pos = 0;

	while (main_pos < start)
		new[new_pos++] = main[main_pos++];
	main_pos = finish + 1;
	while (main_pos < len)
		new[new_pos++] = main[main_pos++];
	new[new_pos] = '\0';
	return (new);
}

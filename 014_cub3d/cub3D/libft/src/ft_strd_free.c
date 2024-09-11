/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:46:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/09 17:12:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h" /* Libreria 42 "jmartos-". */

void	ft_strd_free(char **str)
{
	int	pos;

	pos = 0;
	while (str && str[pos])
	{
		free(str[pos]);
		pos++;
	}
	free(str);
}

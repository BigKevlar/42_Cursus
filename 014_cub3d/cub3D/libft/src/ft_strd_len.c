/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:36:38 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/17 17:21:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h" /* Libreria 42 "jmartos-". */

int	ft_strd_len(char **str)
{
	int	pos;

	pos = 0;
	if (!str)
		return (0);
	while (str[pos])
		pos++;
	return (pos);
}

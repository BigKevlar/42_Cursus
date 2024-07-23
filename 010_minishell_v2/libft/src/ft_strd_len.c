/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:36:38 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/08 19:30:16 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

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

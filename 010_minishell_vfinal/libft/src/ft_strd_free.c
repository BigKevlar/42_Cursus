/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strd_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 22:46:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/08 10:04:35 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* Libreria 42 "jmartos-". */

void	ft_strd_free(char **str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		free(str[pos]);
		pos++;
	}
	free(str);
}

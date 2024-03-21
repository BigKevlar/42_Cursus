/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:08:04 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:59 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit_str(char *str)
{
	int	cont;

	cont = 0;
	if (str == NULL)
		return (0);
	while (str[cont])
	{
		if (str[cont] >= '0' && str[cont] <= '9')
			cont++;
		else
			return (0);
	}
	return (1);
}

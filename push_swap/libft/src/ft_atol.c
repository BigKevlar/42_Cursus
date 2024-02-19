/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:11:29 by jmartos-          #+#    #+#             */
/*   Updated: 2024/02/19 20:28:43 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_atol(const char *str)
{
	int		cont;
	long	num;
	int		aux;

	cont = 0;
	num = 0;
	aux = 1;
	while (str[cont] == ' ' || str[cont] == '\t'
		|| str[cont] == '\v' || str[cont] == '\f'
		|| str[cont] == '\n' || str[cont] == '\r')
		cont++;
	if (str[cont] == '+' || str[cont] == '-')
	{	
		if (str[cont] == '-')
			aux *= -1;
		cont++;
	}
	while (str[cont] >= '0' && str[cont] <= '9' && str[cont] != '\0')
	{
		num = num * 10 + ((int)str[cont] - '0');
		cont++;
	}
	return ((int)num * aux);
}

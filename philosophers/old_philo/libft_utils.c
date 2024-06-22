/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:15:02 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 19:04:20 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atol(char *str)
{
	int		c;
	long	num;
	int		sig;

	c = 0;
	num = 0;
	sig = 1;
	while (str[c] == ' ' || (str[c] >= '\t' && str[c] <= '\r'))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sig = -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9' && str[c] != '\0')
	{
		num = num * 10 + (str[c] - '0');
		c++;
	}
	return ((int)num * sig);
}

int	ft_check_int(long num)
{
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:15:02 by jmartos-          #+#    #+#             */
/*   Updated: 2024/04/29 18:46:48 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atol(char *str, t_stack *s)
{
	int		c;
	long	num;
	int		sign;

	c = 0;
	num = 0;
	sign = 1;
	while (str[c] == ' ' || (str[c] >= '\t' && str[c] <= '\r'))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9' && str[c] != '\0')
	{
		num = num * 10 + (str[c] - '0');
		if (num > INT_MAX || (num * sign) < INT_MIN)
			error_and_free(s, "Error");
		c++;
	}
	return ((int)num * sign);
}

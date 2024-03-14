/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:48:55 by jmartos           #+#    #+#             */
/*   Updated: 2024/03/14 17:58:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *str, t_stack *s)
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
			error_and_free(s, "Error en 'ft_atol'.");
		c++;
	}
	return ((int)num * sign);
}

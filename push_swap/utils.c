/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:48:55 by jmartos           #+#    #+#             */
/*   Updated: 2024/03/09 18:39:35 by jmartos          ###   ########.fr       */
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
		if (num > INT_MAX || (num * sign) < INT_MIN || ft_strlen(str) > 11)
			error_and_free(s, "Error en 'ft_atol'.");
		if (!(str[c] >= '0' && str[c] <= '9'))
			error_and_free(s, "Error en 'ft_atol'.");
		num = num * 10 + ((int)str[c] - '0');
		c++;
	}
	return ((int)num * sign);
}

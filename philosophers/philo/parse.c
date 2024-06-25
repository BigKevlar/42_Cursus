/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:22:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/25 18:48:10 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* (check_int) */
static int	check_long_max_min(long num)
{
	if (num > LONG_MAX || num < LONG_MIN)
		return (1);
	return (0);
}

/* Comprobamos si los parametros respetan el LONG_MAX e INT_MAX. */
int	check_int(char **av)
{
	if (check_long_max_min(ft_atol(av[1])) 
	|| check_long_max_min(ft_atol(av[2]))
	|| check_long_max_min(ft_atol(av[3]))
	|| check_long_max_min(ft_atol(av[4])))
	{
		printf(RED"ERROR! (check_int)\n"END);
		return (1);
	}
	if (av[5])
	{
		if (check_long_max_min(ft_atol(av[5])))
		{
			printf(RED"ERROR! (check_int)\n"END);
			return (1);
		}
	}	
	return (0);
}
/* Comprobamos que no haya caracteres de control en los parametros. */
int	check_args(char **av)
{
	int	c1;
	int	c2;

	c1 = 1;
	while (av[c1])
	{
		c2 = 0;
		while (av[c1][c2])
		{
			if (av[c1][c2] < '0' || av[c1][c2] > '9')
			{
				printf(RED"ERROR! (ckeck_args)\n"END);
				return (1);
			}
			c2++;
		}
		c1++;
	}
	return (0);
}

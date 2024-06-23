/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:22:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/23 20:16:07 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Input:	av[0] = programa
			av[1] = numeros_de_filosofos
			av[2] = tiempo_para_morir
			av[3] = tiempo_en_comer
			av[4] = tiempo_de_dormir
			av[5] = [limite_de_comidas] (opcional)
		Ej.:
							ms	ms	ms
			./philo		5	800	200 200 [5]
		
	Para convertir int (seg) a ms se tiene que multiplicar por 1000,
	que significa 10^3 o 1e3.
*/

static int	check_long_max_min(long num)
{
	if (num > LONG_MAX || num < LONG_MIN)
		return (1);
	return (0);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:22:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 16:13:43 by kevlar           ###   ########.fr       */
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

void	parse_input(t_table *table, char **av)
{
	table->chairs = ft_atol(av[1]);
	table->time2die = ft_atol(av[2]) * 1e3;
	table->time2eat = ft_atol(av[3]) * 1e3;
	table->time2sleep = ft_atol(av[4]) * 1e3;

	if (ft_check_int(table->chairs) 
		|| ft_check_int(table->time2die) 
		|| ft_check_int(table->time2eat) 
		|| ft_check_int(table->time2sleep))
		error_exit("ERROR, it doesnt respect the INT_MAX or INT_MIN.");
	if (table->time2die < 6e4 
		|| table->time2eat < 6e4 
		|| table->time2sleep < 6e4)
		error_exit("ERROR, the timestamps will be higher tanh 60ms.");
	if (av[5])
		table->meals_limit = ft_atol(av[5]);
	else
		table->meals_limit = -1; 
}
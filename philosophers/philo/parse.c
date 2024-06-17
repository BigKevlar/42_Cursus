/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:22:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 15:20:17 by kevlar           ###   ########.fr       */
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
	table->num_philos = atol(av[1]);
	table->time_2_die = atol(av[2]) * 1e3;
	table->time_2_eat = atol(av[3]) * 1e3;
	table->time_2_sleep = atol(av[4]) * 1e3;

	if (check_int(table->num_philos) 
		|| check_int(table->time_2_die) 
		|| check_int(table->time_2_eat) 
		|| check_int(table->time_2_sleep))
		error_and_exit("ERROR, it doesnt repect the INT_MAX or INT_MIN.");
	if (table->time_2_die < 6e4 
		|| table->time_2_eat < 6e4 
		|| table->time_2_sleep < 6e4)
		error_and_exit("ERROR, the timestamps will be higher tanh 60ms.");
	if (av[5])
		table->meals_limit = atol(av[5]);
	else
		table->meals_limit = -1; 
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:04:07 by jmartos           #+#    #+#             */
/*   Updated: 2024/06/24 23:49:37 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Para tener en cuenta las posiciones de los filosofos y de los tenedores:
		
		- Los filosofos tienen diferentes posiciones (chairs = 1, 2, 3, ...)
		y direrentes id (philo 0, philo, 1, philo 2, ...).
			
		- Los tenedores cambian segun si el filosofo tiene id par o impar.
*/

int	table_init(int ac, char **av, t_table *table)
{
	table->philo_count = ft_atol(av[1]);
	table->time2die = ft_atol(av[2]);
	table->time2eat = ft_atol(av[3]);
	table->time2sleep = ft_atol(av[4]);
	if (ac == 6)
		table->meals_limit = ft_atol(av[5]);
	else
		table->meals_limit = -1;
	table->out = 0;
	if (table->philo_count < 1 || table->meals_limit == 0)
	{
		printf(RED"ERROR! (table_init)\n"END);
		return (1);
	}
	table->all_full = 0;
	return (0);
}

int	philo_init(t_table *table)
{
	int	pos;

	pos = 0;
	table->philos = ft_calloc(sizeof(t_philo), table->philo_count);
    table->is_dead = 0;
	while (pos < table->philo_count)
	{
		table->philos[pos].id = pos + 1;
		table->philos[pos].meals_counter = 0;
		table->philos[pos].last_meal = 0;
		table->philos[pos].R_fork = pos;
		table->philos[pos].L_fork = (pos + 1) % table->philo_count;
		table->philos[pos].table = table;
		pos++;
	}
	table->philos[table->philo_count - 1].R_fork = table->philo_count - 1;
	table->philos[table->philo_count - 1].L_fork = 0;
	return (0);
}

int	fork_init(t_table *table)
{
	int	pos;

	pos = 0;
	table->forks = ft_calloc(sizeof(pthread_mutex_t), table->philo_count);
	while (pos < table->philo_count)
	{
		if (pthread_mutex_init(&table->forks[pos], NULL) != 0)
			return (1);
		pos++;
	}
	if (pthread_mutex_init(&table->write_mutex, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->eating, NULL) != 0)
		return (1);
	return (0);
}
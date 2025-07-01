/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:04:07 by jmartos           #+#    #+#             */
/*   Updated: 2024/06/26 06:11:22 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_init(t_philo *philo, t_table	*table, int pos)
{
	int	pos;

	pos = 0;
	table->philos = ft_calloc(sizeof(t_philo), table->philo_count);
	while (pos < table->philo_num)
	{
		philos[pos].pos = pos + 1;
		philos[pos].meals_counter = 0;
		philos[pos].last_meal = 0;
		sem_last_meal = sem_open("/sem_last_meal", O_CREAT, 0644, 1);
		philos[pos].table = table;
		pos++;
	}
	return (0);
}

void	sem_init(t_table *table)
{
	table->sem_forks = sem_open("/sem_forks", O_CREAT, 0644, table->philo_num);
	table->sem_monitor = sem_open("/sem_monitor", O_CREAT, 0644, 1);
	table->sem_finish = sem_open("/sem_finish", O_CREAT, 0644, 1);
	sem_wait(table->sem_finish);
}

int	table_init(int ac, char **av, t_table *table)
{
	int	c;

	c = 0;
	table->philo_num = ft_atol(av[1]);
	table->time2die = ft_atol(av[2]);
	table->time2eat = ft_atol(av[3]);
	table->time2sleep = ft_atol(av[4]);
	if (av[5])
		table->meals_limit = (av[5]);
	else
		table->meals_limit = -1;
	table->start_time = get_time();
	init_sem(table);
	philo_init(&table->philos[c], table, c);
}

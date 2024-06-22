/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:21:15 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/23 00:47:11 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// en el caso que solo hubiese un solo filosofo...
// esta funcion me he basado mucho en la de yash, que me explico que como
// carajillos me complicaba la vida, si es un philo muere al instante
// porque no puede comer con un solo tenedor... haichiwuwa es verdad... ^^uU

void	only_one_philo(t_philo *philo)
{
	printf(BLUE "[%lu ms] philo nº%d has taken a fork.\n"RES, get_time(), 1);
	custom_usleep(philo->table->time2die, philo->table);
	printf(RED "[%lu ms] philo nº%d his dead!\n"RES, get_time(), 1);
}

int	start_game(t_table *table)
{
	int			pos;
	pthread_t	*tid;

	tid = ft_calloc(sizeof(pthread_t), table->philo_count + 1);
	pos = 0;
	while (pos < table->philo_count)
	{
		if (pthread_create(&tid[pos], NULL, (void *)dinner, (void *)&table->philos[pos]))
		{
			printf("ERROR");
			return (1);
		}
		pos++;
	}
	if (pthread_create(&tid[pos], NULL, (void *)check_death, (void *)table))
	{
			printf("ERROR");
			return (1);
	}
	pos = 0;
	while (pos < table->philo_count + 1)
	{
		pthread_join(tid[pos], NULL); // para la ejecucion de cada uno de los hilos.
		pos++;
	}
	return (0);
}

void	table_clean(t_table *table)
{
	int		pos;     

	pos = 0;
	pthread_mutex_destroy(&table->write_mutex);	
	pthread_mutex_destroy(&table->eating);	
	while (pos < table->philo_count)
	{
		pthread_mutex_destroy(&table->forks[pos]);
		pos++;
	}
	free(table->philos);
	free(table->forks);
}

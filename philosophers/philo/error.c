/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:56:39 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/23 01:00:27 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// FUNCIÓN DE ERROR.
void	error_exit(char *msg)
{
	printf(RED"%s\n"RES, msg);
	exit(EXIT_FAILURE);
}

void	the_end(t_table *table)
{
	int	pos;

	pos = 0;
	while (pos < table->philo_count)
	{
		forks_unlock(&table->philos[pos]);
		pthread_mutex_destroy(&table->forks[pos]);
		pos++;
	}
	pthread_mutex_destroy(&table->write_mutex);
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}
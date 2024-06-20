/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:21:15 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/20 17:39:36 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// en el caso que solo hubiese un solo filosofo...
// esta funcion me he basado mucho en la de "occean", en youtube, ya
// que no se me habia ocurrid barajar esta opcion...
void	*only1philo(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	waiting_threads(philo->table);
	set_long(&philo->philo_mutex, &philo->last_meal, get_time());
	threads_counter(&philo->table->table_mutex, &philo->table->threads_running);
	write_status(TAKE_L_FORK, philo);
	while (!table_finish(philo->table))
		usleep(200);	
	return (NULL);
}

void	table_clean(t_table *table)
{
	int		c;     
	t_philo *philo;

	c = 0;
	while (c < table->chairs)
	{
		philo = table->philos + c;
		mutex_handle(&philo->philo_mutex, DESTROY);
		c++;
	}
	mutex_handle(&table->table_mutex, DESTROY);
	mutex_handle(&table->write_mutex, DESTROY);	
	free(table->philos);
	free(table->forks);
}
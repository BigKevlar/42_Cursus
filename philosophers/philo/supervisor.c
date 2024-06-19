/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:18:42 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/20 01:04:20 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
Tenemos que verificar si last_meal es mayor que time2die
para saber si el philo ha muerto de inadicion...

*/

static bool	philo_die(t_philo *philo)
{
	long	time_meals;
	long	time_die;
	
	time_meals = get_time(MILISECOND) - get_long(&philo->philo_mutex, &philo->last_meal);
	time_die = philo->table->time2die / 1e3; // gracais youtube!!!!!!!!!!!
	if (get_bool(&philo->philo_mutex, &philo->full))
		return (false);
	if (time_meals > time_die)
		return (true);
	else
		return (false);
}

void	supervisor(void *data)
{
	t_table	*table;	
	int c;
	
	table = (t_table *)data;
	c = 0;
	// hay que estar seguros de que los hilos estan corriendo
	// este spinlock no dejara avanzar hasta que se cumpla.
	while (!threads_ready(&table->table_mutex, &table->threads_running, &table->chairs))
		;
	while (!table_finish(table))
	{
		while (c < table->chairs && !table_finish(table))
		{
			if(philo_die(table->philos)) //?????????????????????????
			{
				set_bool(&table->table_mutex, &table->end_program, true);
				write_status(DIE, table->philos + 1);
			}
		}
	}
}
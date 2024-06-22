/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:55:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/20 17:54:27 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	man gettimeofday (sys/time.h) para ver la estruccutra del tiempo.

	SECOND - 
	MILISECOND - 
	MICROSECON - 
*/

/*
	PODRIAMOS HACER UNA FUNCION PARA "DBUGEAR" LA ESCRITURA DE LOS STATUS???
*/

void	*safe_malloc(size_t bytes)
{
	void	*value;

	value = malloc(bytes);
	if (NULL == value)
		error_exit("Error with the malloc");
	return (value);
}

long	get_time(void)
{
	static struct timeval	start;
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	if (!start.tv_sec && !start.tv_usec)
		start = tv;
	return (((tv.tv_sec - start.tv_sec) * 1000) + ((tv.tv_usec - start.tv_usec)
			/ 1000));
}


void	custom_usleep(long ms, t_table *table)
{
	long	end;

	end = get_time() + ms;
	while (get_time() < end && !table_finish(table))
		usleep(42);
}

void	write_status(t_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time() - philo->table->start_program;
	if (philo->full)
		return ;
		
	// LOCK!!!
	mutex_handle(&philo->table->write_mutex, LOCK);
	if ((TAKE_L_FORK == status || TAKE_R_FORK == status) && !table_finish(philo->table))
		printf(PURPLE"%-6ld %ld has taken a fork\n"RES, elapsed, philo->id);
	else if (EAT == status && !table_finish(philo->table))
		printf(GREEN"%-6ld %ld is eating\n"RES, elapsed, philo->id);
	else if (SLEEP == status && !table_finish(philo->table))
		printf(BLUE"%-6ld %ld is sleeping\n"RES, elapsed, philo->id);
	else if (THINK == status && !table_finish(philo->table))
		printf(YELLOW"%-6ld %ld is thinking\n"RES, elapsed, philo->id);
	else if (DIE == status)
		printf(RED"%-6ld %ld is dead\n"RES, elapsed, philo->id);

	// UNLOCK!!!
	mutex_handle(&philo->table->write_mutex, UNLOCK);
}

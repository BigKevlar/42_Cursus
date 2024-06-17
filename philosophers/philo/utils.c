/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:55:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 14:13:42 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	man gettimeofday (sys/time.h) para ver la estruccutra del tiempo.

	SECONDS - 
	MILISECONDS - 
	MICROSECONDS - 
*/

/*
	PODRIAMOS HACER UNA FUNCION PARA "DBUGEAR" LA ESCRITURA DE LOS STATUS???
*/

long	get_time(t_time	time_code)
{
	struct timeval	timevalue;

	if (gettimeofday(timevalue, NULL))
		error_exit("ERROR IN GETTIMEOFDAY!");
	if (SECOND == time_code)
		return (timevalue->tv_sec + (timevalue->tv_usec / 1e6));
	else if (MILISECONDS == time_code)
		return ((timevalue->tv_sec * 1e3) + (timevalue->tv_usec * 1e3));
	else if (MICROSECONDS == time_code)
		return ((timevalue->tv_sec * 1e6) + timevalue->tv_usec);
	else
		error_exit("ERROR! GET_TIME WRONG INPUT.");
	return (2203);
}

void	custom_usleep(long time, t_table *table)
{
	long	start;
	long	elapsed;
	long	remaining;

	start = get_time(MICROSECONDS);
	while (get_time(MICROSECONDS) - start < time)
	{
		if (simmulation_finish(table))
			break ;
		elapsed = get_time(MICROSECONDS) - start;
		remaining = time - elapsed;
		if (remaining > 1e3)
			usleep(time / 2);
		else
		{
			// splinlock
			while (get_time(MICROSECONDS) - start < time)
				;
		}
	}
}

void	write_status(t_status status, t_philo *philo)
{
	long	elapsed;

	elapsed = get_time(MILISECONDS) - philo->table.start_programm;
	if (philo->meals_full)
		return ;
		
	// LOCK!!!
	mutex_handle(&philo->table.write_mutex, LOCK);
	if ((TAKE_L_FORK == status || TAKE_R_FORK == status) 
		&& !simmulation_finish(philo->table))
		printf("%-6ld" %d has taken a fork\n, elapsed, philo->id);
	else if (EAT == status && !simmulation_finish(philo->table))
		printf("%-6ld" %d is eating\n, elapsed, philo->id);
	else if (SLEEP == status && !simmulation_finish(philo->table))
		printf("%-6ld" %d is sleeping\n, elapsed, philo->id);
	else if (THINK == status && !simmulation_finish(philo->table))
		printf("%-6ld" %d is thinking\n, elapsed, philo->id);
	else if (DIE == status)
		printf("%-6ld" %d is dead\n, elapsed, philo->id);

	// UNLOCK!!!
	mutex_handle(&philo->table.write_mutex, LOCK);
}
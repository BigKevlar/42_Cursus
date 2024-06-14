/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:55:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/14 22:51:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	man gettimeofday (sys/time.h) para ver la estruccutra del tiempo.

	SECONDS - 
	MILISECONDS - 
	MICROSECONDS - 
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
	
}
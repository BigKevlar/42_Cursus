/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:55:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/23 20:20:34 by kevlar           ###   ########.fr       */
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

long	get_time(void)
{
	static struct timeval	start;
	struct timeval			tv;

	gettimeofday(&tv, NULL);
	if (!start.tv_sec && !start.tv_usec)
		start = tv;
	return (((tv.tv_sec - start.tv_sec) * 1000) + 
		((tv.tv_usec - start.tv_usec) / 1000));
}


void	custom_usleep(long time, t_table *table)
{
	long	end;

	end = get_time() + time;
	while (get_time() < end && !table->finish_program)
		usleep(42);
}


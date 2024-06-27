/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:55:56 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/26 01:22:37 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	static struct timeval	start;
	struct timeval			time;

	gettimeofday(&time, NULL);
	if (!start.tv_sec && !start.tv_usec)
		start = time;
	return (((time.tv_sec - start.tv_sec) * 1000)
		+ ((time.tv_usec - start.tv_usec) / 1000));
}

void	custom_usleep(long time, t_table *table)
{
	long	end;

	end = get_time() + time;
	while (get_time() < end && !table->out)
		usleep(500);
}

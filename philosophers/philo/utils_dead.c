/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:35:59 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/23 00:32:09 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_diying(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) > (long)philo->table->time2die)
	{
		set_dead(philo);
		printf(RED"[%lu ms] philo nº%ld is dead.\n"RES, get_time(), philo->id);
		return (1);
	}
	return (0);
}

void	is_dead(t_table *table, int *diying, int *pos)
{
	if (ft_diying(&table->philos[*pos]))
		*diying = 1;
}

void dead(int die, int finish, int c, t_table *table)
{
	while (die < table->philo_count)
	{
		is_dead(table, &die, &c);
		if (die)
			break;
		if (get_meal_counter(&table->philos[c]) >= table->meals_limit
			&& table->meals_limit != -1)
			finish++;
		die++;
	}
}

void	check_death(void *tmp_table)
{
	t_table	*table;
	long	c;
	long 	finish;
	long	die;

	table = (t_table *)tmp_table;
	c = 0;
	finish = 0;
	die = 0;
	while (!die)
	{
		die = 0;
		// TODO
		dead(die, finish, c, tmp_table);
		// TODO
		if (finish == table->philo_count)
			break ;
		custom_usleep(5, table);
	}
	set_out(table);
}
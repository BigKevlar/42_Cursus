/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:35:59 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/24 20:47:41 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_diying_1(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) > (long)philo->table->time2die)
	{
		set_dead(philo);
		printf(RED"[%ld ms] philo nº%ld is dead.\n"END, get_time(), philo->id);
		exit (1);
	}
	return (0);
}

void ft_diying_2(t_table *table, int *is_full, int *pos)
{
	if (ft_diying_1(&table->philos[*pos]))
		*is_full = 1;
}

void dead(int *is_dead, int *is_full, int *pos, t_table *table)
{
	while (*is_dead < table->philo_count)
	{
		ft_diying_2(table, is_dead, pos);
		if (*is_dead)
			break;
		if (get_meal_counter(&table->philos[*pos]) >= table->meals_limit && table->meals_limit != -1)
			(*is_full)++;
	}
}

void check_death(void *tmp_table)
{
	t_table *table;

	table = (t_table *)tmp_table;
	while (get_dead(table->philos) == 0)
	{
		dead(&table->is_dead, &table->is_dead, &table->philos->pos, table);
		if (get_dead(table->philos))
			break;
		custom_usleep(5, table);
	}
	set_out(table);
}

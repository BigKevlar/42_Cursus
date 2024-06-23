/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:35:59 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/23 22:29:41 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_diying_1(t_philo *philo)
{
	if (get_time() - get_last_meal(philo) > (long)philo->table->time2die)
	{
		set_dead(philo);
		printf(RED"[%ld ms] philo nº%ld is dead.\n"END, get_time(), philo->id);
		return (1);
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
	while (table->philos->is_dead == 0)
	{
		dead(&table->philos->is_dead, &table->philos->is_dead, &table->philos->pos, table);
		printf("is_dead = %d\n", table->philos->is_dead);
		printf("philo_count = %ld\n", table->philo_count);
		if (table->philos->is_dead == table->philo_count)
			break;
		custom_usleep(5, table);
	}
	printf("get_time = %ld - get_last_meal = %ld\n", get_time(), get_last_meal(table->philos));
	set_out(table);
}

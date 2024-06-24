/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:35:59 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/24 23:46:56 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// a muerto algun filosofo???
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

// si esta muerto marcamos el parametro de is_dead como 1.
void ft_diying_2(t_table *table, int *is_dead, int *pos)
{
	if (ft_diying_1(&table->philos[*pos]))
		*is_dead = 1;
}

// verificamos si algun fiosofo a muerto o estan todos llenos.
void dead_or_full(int *is_dead, int *all_full, int *pos, t_table *table)
{
	while (*is_dead < table->philo_count)
	{
		ft_diying_2(table, is_dead, pos);
		if (*is_dead)
			break;
		if (get_meal_counter(&table->philos[*pos]) >= table->meals_limit && table->meals_limit != -1)
			(*all_full)++;
	}
}

void check_dead(void *tmp_table)
{
	t_table *table;
	int 	pos;

	table = (t_table *)tmp_table;
	while (get_dead(table->philos) == 0)
	{
		pos = 0;
		dead_or_full(&table->is_dead, &table->all_full, &pos, table);
		if (get_dead(table->philos))
			break;
		custom_usleep(5, table);
	}
	set_out(table);
}

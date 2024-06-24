/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:54:58 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/24 22:24:00 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	set_meal_counter(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	philo->meals_counter++;
	if(philo->meals_counter == philo->table->meals_limit)
		philo->table->all_full++;
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	set_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	philo->table->is_dead = 1;
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	set_out(t_table *table)
{
	pthread_mutex_lock(&table->write_mutex);
	table->out = 1;
	pthread_mutex_unlock(&table->write_mutex);
}

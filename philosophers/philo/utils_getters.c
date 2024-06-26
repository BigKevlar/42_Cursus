/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:54:58 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/26 01:14:48 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_last_meal(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->table->write_mutex);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->table->write_mutex);
	return (last_meal);
}

int	get_meal_counter(t_philo *philo)
{
	int	meals_counter;

	pthread_mutex_lock(&philo->table->write_mutex);
	meals_counter = philo->meals_counter;
	pthread_mutex_unlock(&philo->table->write_mutex);
	return (meals_counter);
}

int	get_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->table->write_mutex);
	dead = 0;
	if (philo->table->is_dead
		|| philo->table->all_full == philo->table->philo_count)
		dead = 1;
	pthread_mutex_unlock(&philo->table->write_mutex);
	return (dead);
}

int	get_out(t_table *table)
{
	int	out;

	pthread_mutex_lock(&table->write_mutex);
	out = table->out;
	pthread_mutex_unlock(&table->write_mutex);
	return (out);
}

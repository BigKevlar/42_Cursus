/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:54:58 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/22 22:20:32 by kevlar           ###   ########.fr       */
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
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	set_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->write_mutex);
	philo->is_dead = 1;
	pthread_mutex_unlock(&philo->table->write_mutex);
}

void	set_out(t_table *table)
{
	pthread_mutex_lock(&table->write_mutex);
	table->finish_program = 1;
	pthread_mutex_unlock(&table->write_mutex);
}

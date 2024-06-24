/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:37:21 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/24 23:09:58 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->L_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->R_fork]);
}

static int	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->table->forks[philo->L_fork]) != 0)
		return (1);
	if (check_write(philo, FORK) || pthread_mutex_lock(&philo->table->forks[philo->R_fork]) != 0)
			return (1);
	if (check_write(philo, FORK) || pthread_mutex_lock(&philo->table->eating) != 0)
			return (1);
	if (check_write(philo, EAT) || pthread_mutex_unlock(&philo->table->eating) != 0)
		return (1);
	set_last_meal(philo);
	set_meal_counter(philo);
	printf("philo nº%ld meals_counter = %ld ******\n", philo->id, philo->meals_counter);
	custom_usleep(philo->table->time2eat, philo->table);
	if (pthread_mutex_unlock(&philo->table->forks[philo->L_fork]) != 0)
		return (1);
	if (pthread_mutex_unlock(&philo->table->forks[philo->R_fork]) != 0)
		return (1);
	return (0);
}

static int	philo_sleep(t_philo *philo)
{
	if (check_write(philo, SLEEP))
		return (1);
	custom_usleep(philo->table->time2sleep, philo->table);
	return (0);
}

static int	philo_think(t_philo *philo)
{
	if (check_write(philo, THINK))
		return (1);
	return (0);
}

void	*dinner(void *tmp_philo)
{
	t_philo	*philo;

	philo = (t_philo *)tmp_philo;
	if (philo->id % 2 == 0) // que los philos pares esperen un poco antes ue lso impares.
		usleep(500);
	while (!get_dead(philo) && !get_out(philo->table) && (philo->table->meals_limit == -1 || philo->meals_counter < philo->table->meals_limit))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	forks_unlock(philo); // cuando los fios terminan, forzamos a desboquear los tenedores.
	return (NULL);
}

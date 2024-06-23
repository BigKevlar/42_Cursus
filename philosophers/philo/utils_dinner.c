/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:37:21 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/23 23:46:56 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->forks[philo->L_fork]);
	pthread_mutex_unlock(&philo->table->forks[philo->R_fork]);
}

// vamos a poner delante "philo" para evitar problemas con la macro de unistd.h

static void	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->table->forks[philo->L_fork]) != 0) // 
		return ;
	if (pthread_mutex_lock(&philo->table->forks[philo->R_fork]) != 0)
		return ;
	printf(CYAN"[%lu ms] philo nº%ld has taken a fork.\n"END, get_time(), philo->id);
	printf(CYAN"[%lu ms] philo nº%ld has taken a fork.\n"END, get_time(), philo->id);
	if (pthread_mutex_lock(&philo->table->eating) != 0)
		return ;
	printf(GREEN"[%lu ms] philo nº%ld is eating.\n"END, get_time(), philo->id);
	if (pthread_mutex_unlock(&philo->table->eating) != 0)
		return ;
	set_last_meal(philo);
	custom_usleep(philo->table->time2eat, philo->table);
	set_meal_counter(philo);
	if (pthread_mutex_unlock(&philo->table->forks[philo->L_fork]) != 0)
		return ;
	if (pthread_mutex_unlock(&philo->table->forks[philo->R_fork]) != 0)
		return ;
}

static void	philo_sleep(t_philo *philo)
{
	printf(BOLD ORANGE"[%lu ms] philo nº%ld is sleeping.\n"END, get_time(), philo->id);
	custom_usleep(philo->table->time2sleep, philo->table);
}

static void	philo_think(t_philo *philo)
{
	printf(PURPLE"[%lu ms] philo nº%ld is thinking.\n"END, get_time(), philo->id);
}

void	*dinner(void *tmp_philo)
{
	t_philo	*philo;

	philo = (t_philo *)tmp_philo;
	if (philo->id % 2 == 0)
		usleep(142);
	else
		usleep(42);
	while (!(get_dead(philo) || get_out(philo->table)))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		//printf("meals_counter: %ld\n", philo->meals_counter);
	}
	forks_unlock(philo);
	return (NULL);
}

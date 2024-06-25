/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:21:15 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/25 22:15:26 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// en el caso que solo hubiese un solo filosofo...
// esta funcion me he basado mucho en la de yash, que me explico que como
// carajillos me complicaba la vida, si es un philo muere al instante
// porque no puede comer con un solo tenedor... haichiwuwa es verdad... ^^uU

void	only_one_philo(t_philo *philo)
{
	printf("[%lu ms] philo nº%d has taken a fork.\n", get_time(), 1);
	custom_usleep(philo->table->time2die, philo->table);
	printf(RED"[%lu ms] philo nº%d his dead!\n"END, get_time(), 1);
}
/*
	Funcion principal. Creamos pos para iterar con los philos y una estructura
	tipo hilo llamado philo. Hacemos un bucle con pthread_create a los hilos
	con llamada a la funcion dinner (utils_dinner). Luego hacemos un hilo de
	nuevo, con llamada a check_dead (utils_dead) para monitorear las muertes.
	Luego con pthread_join esperamos a que todos los hilos esten listos.
*/
int	start_game(t_table *table)
{
	int			pos;
	pthread_t	*philo;

	philo = ft_calloc(sizeof(pthread_t), table->philo_count + 1);
	pos = 0;
	while (pos < table->philo_count)
	{
		if (pthread_create(&philo[pos], NULL, (void *)dinner, (void *)&table->philos[pos])) // crea hilo para cada philo.
		{
			printf(RED"ERROR! (start_game)\n"END);
			return (1);
		}
		pos++;
	}
	if (pthread_create(&philo[pos], NULL, (void *)check_dead, (void *)table)) // crea hilo para monitorear las muertes.
	{
			printf(RED"ERROR! (start_game)\n"END);
			return (1);
	}
	pos = 0;
	while (pos < table->philo_count + 1) // espera a que todos los hilos esten llistos
	{
		pthread_join(philo[pos], NULL);
		pos++;
	}
	return (0);
}

void	the_end(t_table *table)
{
	int	pos;

	pos = 0;
	
	while (pos < table->philo_count)
	{
		forks_unlock(&table->philos[pos]);
		pthread_mutex_destroy(&table->forks[pos]);
		pos++;
	}
	pthread_mutex_destroy(&table->write_mutex);
	pthread_mutex_destroy(&table->eating);	
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

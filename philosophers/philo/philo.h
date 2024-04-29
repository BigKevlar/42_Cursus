/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/04/29 18:45:39 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// write.
# include <unistd.h>
// printf.
# include <stdio.h>
// 
# include <stdlib.h>
// atoi y size_t.
# include <string.h>
// Listas e hilos.
# include <pthread.h>
// INT_MIN y INT_MAX.
# include <limits.h>

typedef struct	s_philo
{
	int						id;
	pthread_mutex_t			l_fork;
	pthread_mutex_t			r_fork;
	long long				last_meal;
	t_table					common;
}							t_philo;

typedef struct	s_table
{
	int			number;
	int			t_init;
	int			t_current;
	int			t_dead;
	int			t_eat;
	int			t_sleep;	
}				t_table;

#endif
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

// write y usleep.
# include <unistd.h>
// printf.
# include <stdio.h>
// malloc y free.
# include <stdlib.h>
// atoi y size_t.
# include <string.h>
// Listas e hilos y mutex.
# include <pthread.h>
// bool (true or false)
# include <stdbool.h>
// getttimeofday
# include <sys/time.h>
// INT_MIN y INT_MAX.
# include <limits.h>

# define RESET			"\033[0m"
# define RED			"\033[31;1m"
# define GREEN			"\033[32;1m"
# define YELLOW			"\033[33;1m"
# define BLUE			"\033[34;1m"

typedef struct	s_philo
{
	int					id;
	long long			meals_counter;
	long long			last_meal;
	bool				full_eat;
	int					time_2_think;
	int					time_2_eat;
	int					time_2_sleep;
	pthread_mutex_t		L_fork;
	pthread_mutex_t		R_fork;
}						t_philo;

typedef struct	s_table
{
	int		start;
	long	time_2_think;
	long	time_2_eat;
	long	time_2_sleep;
}			t_table;

/***************/
/* FUNCTIONS.C */
/***************/
void	error_and_exit(char *msg);
/***********/
/* UTILS.C */
/***********/
int	ft_atol(char *str, t_stack *s);

#endif
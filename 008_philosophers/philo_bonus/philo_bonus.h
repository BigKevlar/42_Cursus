/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/26 05:57:45 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>	// write y usleep
# include <stdio.h>		// printf
# include <stdlib.h>	// malloc, free y atoi
# include <string.h>	// size_t
# include <pthread.h>	// hilos --> create | join | detach 
						// mutex --> init | destroy | lock | unlock
# include <errno.h>		// codigos de errores
# include <stdbool.h>	// bool
# include <sys/time.h>	// getttimeofday
# include <limits.h>	// INT_MIN y INT_MAX
# include <fcntl.h>		// For O_* constants
# include <sys/stat.h>	// For mode constants
# include <semaphore.h>	// semaphores

/* Por si queremo usar colorinchis! */
# define END	"\033[0m"
# define BOLD	"\033[1m"
# define BLACK	"\033[30;1m"
# define RED	"\033[31;1m"
# define GREEN	"\033[32;1m"
# define YELLOW	"\033[33;1m"
# define BLUE	"\033[34;1m"
# define PURPLE "\033[35;1m"
# define CYAN	"\033[36;1m"
# define WHITE	"\033[37;1m"
# define ORANGE	"\033[38;5;208m"
# define PINK	"\033[38;5;205m"

/* Macros, para las comidas (utils_write.c). */
# define FORK	"has taking a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"

/* Declaramos la t_table al principio para que no de problemas de 
"unknow type" al hacer make. */
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

/* Cada philo es un proceso hijo. */
typedef struct s_philo
{
	int			pid;
	long		pos;
	long		meals_counter;
	long		last_meal;
	sem_t		*sem_last_meal;
	t_table		*table;
}				t_philo;

/* La mesa sera el proceso padre. */
typedef struct s_table
{
	long		philo_num;
	long		time2die;
	long		time2eat;
	long		time2sleep;
	long		meals_limit;
	long		start_time;
	sem_t		*sem_forks;
	sem_t		*sem_monitor;
	sem_t		*sem_finish;
	t_philo		*philos;
}				t_table;

#endif
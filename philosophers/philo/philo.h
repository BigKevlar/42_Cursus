/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/23 00:04:01 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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

# define RES	"\033[0m"
# define RED	"\033[31;1m"
# define GREEN	"\033[32;1m"
# define YELLOW	"\033[33;1m"
# define BLUE	"\033[34;1m"
# define PURPLE "\033[35;1m"

/* Decaramos la t_table al principio para que no de problemas de "unknow type" al hacer make. */
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

/* Cada philo (filosofo) es un thread (hilo). */

typedef struct	s_philo
{
	long unsigned int	id;
	long				meals_counter;
	long				last_meal;
	int					is_full;
	int					is_dead;
	int					R_fork;
	int					L_fork;
	t_table				*table;
}				t_philo;

/* La mesa sera la estructura principal del proyecto. */

typedef struct	s_table
{
	long				philo_count;
	long				time2die;
	long				time2eat;
	long				time2sleep;
	long				meals_limit;
	int					finish_program;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		eating;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	pthread_t			supervisor;
}				t_table;

// PARSE.C
int		check_int(char **av);
int		check_args(char **av);
// ERROR.C
void	error_exit(char *msg);
// INIT.C
int		table_init(int ac, char **av, t_table *table);
int		philo_init(t_table *table);
int		fork_init(t_table *table);
// UTILS_LIBTF.C
int		ft_atol(char *str);
void	*ft_calloc(size_t count, size_t size);
// UTILS_DEAD.C
int		ft_diying(t_philo *philo);
void	is_dead(t_table *table, int *diying, int *pos);
void 	dead(int die, int finish, int c, t_table *table);
void	check_death(void *tmp_table);
// UTILS_DINNER.C
void	forks_unlock(t_philo *philo);
void	*dinner(void *tmp_philo);
// UTILS_GETTERS.C
long	get_last_meal(t_philo *philo);
int		get_meal_counter(t_philo *philo);
int		get_dead(t_philo *philo);
int		get_out(t_table *table);
// UTILS_SETTERS.C
void	set_last_meal(t_philo *philo);
void	set_meal_counter(t_philo *philo);
void	set_dead(t_philo *philo);
void	set_out(t_table *table);
// UTILS_TIME.C
void	*safe_malloc(size_t bytes);
long	get_time(void);
void	custom_usleep(long ms, t_table *table);
// UTILS_TABLE.C
void	only_one_philo(t_philo *philo);
int		start_game(t_table *table);
void	table_clean(t_table *table);

#endif
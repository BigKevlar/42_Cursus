/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/26 01:01:48 by kevlar           ###   ########.fr       */
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

/* Cada philo es un thread/hilo (ver el t_table). */
typedef struct s_philo
{
	long unsigned int	id;
	long				meals_counter;
	long				last_meal;
	int					r_fork;
	int					l_fork;
	t_table				*table;
}				t_philo;

/* La mesa sera la estructura principal del proyecto. */
typedef struct s_table
{
	long				philo_count;
	long				time2die;
	long				time2eat;
	long				time2sleep;
	long				meals_limit;
	pthread_mutex_t		write_mutex;
	pthread_mutex_t		eating;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	int					out;			//bool
	int					is_dead;		//bool
	int					all_full;		//bool
}				t_table;

/* PARSE.C */
int		check_int(char **av);
int		check_args(char **av);
/* INIT.C */
int		table_init(int ac, char **av, t_table *table);
int		philo_init(t_table *table);
int		fork_init(t_table *table);
/* UTILS_LIBTF.C */
int		ft_atol(char *str);
void	*ft_calloc(size_t count, size_t size);
/* UTILS_DEAD.C */
int		ft_diying_1(t_philo *philo);
void	ft_diying_2(t_table *table, int *is_dead, int *pos);
void	dead_or_full(int *is_dead, int *all_full, int *pos, t_table *table);
void	*check_dead(void *tmp_table);
/* UTILS_DINNER.C */
void	forks_unlock(t_philo *philo);
void	*dinner(void *tmp_philo);
/* UTILS_GETTERS.C */
long	get_last_meal(t_philo *philo);
int		get_meal_counter(t_philo *philo);
int		get_dead(t_philo *philo);
int		get_out(t_table *table);
/* UTILS_SETTERS.C */
void	set_last_meal(t_philo *philo);
void	set_meal_counter(t_philo *philo);
void	set_dead(t_philo *philo);
void	set_out(t_table *table);
/* UTILS_TIME.C */
long	get_time(void);
void	custom_usleep(long time, t_table *table);
/* UTILS_TABLE.C */
void	only_one_philo(t_philo *philo);
int		start_game(t_table *table);
void	the_end(t_table *table);
int		security(t_philo *philo);
/* UTILS_TABLE.C */
int		check_write(t_philo *philo, char *action);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/19 22:57:07 by kevlar           ###   ########.fr       */
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

/* Las opcode (operation codes) las usaremos para los mutex y thread functions. */

typedef enum	e_opcode
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}				t_opcode;

/* Codigos para get_time. */

typedef enum	e_time
{
	SECOND,
	MILISECOND,
	MICROSECOND,
}				t_time;

/* Estados de los philosofos. */

typedef enum	e_status
{
	EAT,
	SLEEP,
	THINK,
	TAKE_L_FORK, // para debuging
	TAKE_R_FORK, // para debuging
	DIE,
}				t_status;

/* Decaramos la t_table al principio para que no de problemas de "unknow type" al hacer make. */
typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

/* Los fork (tenedores) tenedores son mutex (semaforo) para este proyecto. */

typedef struct	s_fork
{
	int					id;
	pthread_mutex_t		fork;
}				t_fork;

/* Cada philo (filosofo) es un thread (hilo). */

typedef struct	s_philo
{
	long unsigned int	id;
	pthread_t			thread;
	long				meals_counter;
	long				last_meal;
	bool				full;
	t_fork				*L_fork;
	t_fork				*R_fork;
	t_table				*table;
	pthread_mutex_t		philo_mutex; // lo usaremos para escribir en pantalla
}				t_philo;

/*
La estructura de parametros recibida para el programa sera la siguiente:
	./philo
		numeros_de_filosofos
		tiempo_para_morir
		tiempo_en_comer
		tiempo_de_dormir
		[limite_de_comidas] (opcional)
*/
/* La mesa sera la estructura principal del proyecto. */

typedef struct	s_table
{
	long				chairs;
	long				time2die;
	long				time2eat;
	long				time2sleep;
	long				meals_limit;
	long				start_program;
	bool				end_program; // valor booleano para cuando los philos esten llenos o uno muera.
	long				threads_running; //  hilos corriendo.
	bool				threads_ready; // cuando es true avisa al supervisor.
	pthread_mutex_t		table_mutex; // ???
	pthread_mutex_t		write_mutex;
	pthread_t			supervisor;
	t_philo				*philos;
	t_fork				*forks;
}				t_table;

/***********/
/* ERROR.C */
/***********/
void		error_exit(char *msg);
/***********/
/* PARSE.C */
/***********/
void    	parse_input(t_table *table, char **av);
/**********/
/* INIT.C */
/**********/
void		table_init(t_table *table);
/***********/
/* MUTEX.C */
/***********/
void		mutex_handle(pthread_mutex_t *mutex, t_opcode opcode);
/*************/
/* THREADS.C */
/*************/
void		thread_handle(pthread_t *thread, void *funct, void *data, t_opcode opcode);
void		waiting_threads(t_table *table);
void		threads_counter(pthread_mutex_t *mutex, long *cont);
bool		threads_ready(pthread_mutex_t *mutex, long *threads_ready, long *philos);
/***********/
/* TABLE.C */
/***********/
void		*dinner_start(void *data);
void		table_start(t_table *table);
void		clean_table(t_table *table);
/*********************/
/* GET_SET_CONTROL.C */
/*********************/
void		set_bool(pthread_mutex_t *mutex, bool *new, bool value);
bool		get_bool(pthread_mutex_t *mutex, bool *value);
void		set_long(pthread_mutex_t *mutex, long *new, long value);
long		get_long(pthread_mutex_t *mutex, long *value);
bool		table_finish(t_table *table);
/***********/
/* UTILS.C */
/***********/
long		get_time(t_time	time_code);
void		custom_usleep(long time, t_table *table);
void		write_status(t_status status, t_philo *philo);
void		*safe_malloc(size_t bytes);
/*****************/
/* LIBFT_UTILS.C */
/*****************/
int			ft_atol(char *str);
int			ft_check_int(long num);

#endif
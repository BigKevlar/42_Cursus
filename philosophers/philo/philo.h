/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/14 22:51:13 by jmartos-         ###   ########.fr       */
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
# define R		"\033[31;1m"
# define G		"\033[32;1m"
# define Y		"\033[33;1m"
# define B		"\033[34;1m"

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
	EAT;
	SLEEP,
	THINK,
	TAKE_L_FORK; // para debuging
	TAKE_R_FORK; // para debuging
	DIE;
}				t_status;

/* Los fork (tenedores) tenedores son mutex (semaforo) para este proyecto. */

typedef struct	s_fork
{
	int					id;
	pthread_mutex_t		fork;
}				t_fork;

/* Cada philo (filosofo) es un thread (hilo). */

typedef struct	s_philo
{
	int					id;
	long long			meals_counter;
	long long			meals_time;
	bool				meals_full;
	t_fork				L_fork;
	t_fork				R_fork;
	t_table				table;
	pthread_mutex_t		thread;
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
	long		chairs;
	long		time_2_die;
	long		time_2_eat;
	long		time_2_sleep;
	long		meals_limit;
	long		start_program;
	bool		end_program; // valor booleano para cuando los philos esten llenos o uno muera.
	bool		threads_ready; // sincroniza los philos
	t_mtx		table_mutex; // ???
	t_mtx		write_mutex;
	t_philo		philos;
	t_fork		forks;
}				t_table;

/***********/
/* ERROR.C */
/***********/
void		error_exit(char *msg);
/***********/
/* PARSE.C */
/***********/
void    	parse_input(t_table *table, char **av)
/**********/
/* INIT.C */
/**********/
void		table_init(t_table *table);
/***********/
/* MUTEX.C */
/***********/
void		mutex_handle(t_mtx *mutex, t_opcode opcode);
/*************/
/* THREADS.C */
/*************/
void		threads_handle(pthread *thread, void *funct, void *data, t_opcode opcode);
/***********/
/* TABLE.C */
/***********/
void		*dinner_start(void *data);
void		table_start(t_table *table);
/*********************/
/* GET_SET_CONTROL.C */
/*********************/
void		set_bool(t_mtx *mutex, bool *new, bool value);
bool		get_bool(t_mtx *mutex, bool *value);
void		set_long(t_mtx *mutex, long *new, long value);
long		get_long(t_mtx *mutex, long *value);
bool		simmulation_finish(t_table *table);
/******************/
/* SYNCRO_UTILS.C */
/******************/
void		waiting_threads(t_table *table);
/*****************/
/* LIBFT_UTILS.C */
/*****************/
int			atol(char *str);
int			check_int(long num);
/***********/
/* UTILS.C */
/***********/
long		get_time(t_time	time_code);
void		custom_usleep(long time, t_table *table);

#endif
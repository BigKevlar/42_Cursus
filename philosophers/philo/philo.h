/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:15:03 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/11 23:54:58 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>	// write y usleep.
# include <stdio.h>		// printf.
# include <stdlib.h>	// malloc, free y atoi.
# include <string.h>	// size_t.
# include <pthread.h>	// hilos --> create | join | detach 
						// mutex --> init | destroy | lock | unlock
# include <stdbool.h>	// bool.
# include <sys/time.h>	// getttimeofday.
# include <limits.h>	// INT_MIN y INT_MAX.

# define RES	"\033[0m"
# define R		"\033[31;1m"
# define G		"\033[32;1m"
# define Y		"\033[33;1m"
# define B		"\033[34;1m"

typedef struct	s_fork // los tenedores son mutex para este proyecto.
{
	int					id;
	pthread_mutex_t		fork;
}				t_fork;

typedef struct	s_philo // cada filosofo es un hilo.
{
	int					id;
	pthread_mutex_t		philo;
	long long			meals_counter;
	long long			meals_time;
	bool				meals_top;
	t_fork				L_fork;
	t_fork				R_fork;
	t_table				table;
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

typedef struct	s_table // la mesa sera la estructura principal del proyecto.
{
	long		num_philos;
	long		time_2_die;
	long		time_2_eat;
	long		time_2_sleep;
	long		meals_limit;
	long		start_program;
	long		end_program;
	t_philo		philos;
	t_fork		forks;
}				t_table;

/********************/
/* MAIN_FUNCTIONS.C */
/********************/
long long	get_time(void);
/***********/
/* ERROR.C */
/***********/
void		error_and_exit(char *msg);
/***********/
/* UTILS.C */
/***********/
int			atol(char *str);
int			check_int(long num);
/***********/
/* PARSE.C */
/***********/
void    	parse_input(t_table *table, char **av)

#endif
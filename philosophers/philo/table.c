/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:50:01 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 15:23:42 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	Input:	./philo 5 800 200 200 [5]
				nombre_del_programa
				numeros_de_filosofos
				tiempo_para_morir
				tiempo_en_comer
				tiempo_de_dormir
				[limite_de_comidas] (opcional)

    1- si no hay meals = return 0
    2- si solo hay un philo = añadir funcion hoc
    3- crear hilos (philos)
    4- crear monitor de hilos, para las muertes
    5- sincronizar la simulaciones:
        phtread_creat -> philo comienzan!!!
        todos los philos empiezan a la vez
    6- juntar todo!!!
*/

/*
	MODO DE PROCEDER PARA "COMER" (funcion eat):
	1- se cogen los tenedores y escribimos que se cogen
	2- comer:	escribimos status de comer
				modificamos meals_counter
				modificamos meals_timer
				modificamos meals_full (si toca)
	3- soltamos los tenedores	
*/

static void	eat(t_philo *philo)
{
	// 1º
	mutex_handle(&philo->L_FORK, LOCK);
	write_status(TAKE_L_FORK, philo);
	mutex_handle(&philo->R_FORK, LOCK);
	write_status(TAKE_R_FORK, philo);
	// 2º
	set_long(&philo->philo_mutex, philo->meals_time, get_time(MILISECONDS));
	philo->meals++;
	write_status(EAT, philo);
	custom_usleep(philo->table.time2eat, philo->table);
	if (philo->table.meals_limit > 0 
		&& philo->meals_counter == philo->table.meals_limit)
		set_bool(&ohilo->philo_mutex &philo->meals_full, true);
	// 3º
	mutex_handle(&philo->L_FORK, UNLOCK);
	mutex_handle(&philo->R_FORK, UNLOCK);

}

static void	think(t_philo *philo)
{
	write_status(THINK, philo);
}

void	*dinner_start(void *data)
{
	t_philo	philo;

	philo = (t_philo *)data;

	//spinlock
	waiting_threads(philo->table);

	// poner tiempo de ultima comida???
	TODO

	while (!simmulation_finish(philo->table))
	{
		// 1º estoy lleno?
		if(philo->meals_full)
			break ;
		else
		{
			// 2º eat
			eat(philo);

			//3º sleep (escribir status y poner "usleep")
			write_status(SLEEPING, philo);
			custom_usleep(philo->table.time2sleep, philo->table);
			
			//4º think
			think(philo);
		}
	}
}

void	table_start(t_table *table)
{
	int pos;

	pos = -1;
	if (0 == table->meals_full)
		return ;
	else if (1 == table->chairs)
		// TODO
	else
	{
		while (pos < table->chairs)
		{
			threads_handle(&table->philos[pos].id, dinner_start, &table->philos[pos], CREATE);
			pos++;
		}	
	}

	// comenzamos la simulacion
	table->start_program = get_time(MILISECONDS);



	// en este punto los hilos ya estan listos!
	set_bool(&t_table->table_mutex, &t_table->threads_ready, true);


	// esperamos a todos los philosofos
	pos = -1;
	while (pos < table->chairs)
	{
		thread_handle(&table->philos[pos].id, NULL, NULL, JOIN);
		pos++;
	}

// a partir de esta llinea todos los philos estan FULL!!!



}

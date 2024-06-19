/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:18:42 by kevlar            #+#    #+#             */
/*   Updated: 2024/06/19 22:57:37 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	supervisor(void *data)
{
	t_table	*table;	
	
	table = (table *)data;
	
	// hay que estar seguros de que los hilos estan corriendo
	// este spinlock no dejara avanzar hasta que se cumpla.
	while (!threads_ready(&table->table_mutex, &table->threads_running, &table->chairs))
		;
	while (!table_finish)
		
}
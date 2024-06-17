/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncro_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:36:46 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 16:28:06 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// spinlock??? bucle para sincronizar el comienzo de los philos???
void	waiting_threads(t_table *table)
{
	while (!get_bool(&table->table_mutex, &table->threads_ready))
		;
}
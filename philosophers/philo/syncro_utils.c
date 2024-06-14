/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syncro_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:36:46 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/14 22:51:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// spinlock??? bucle para sincronizar el comienzo de los philos???
void	waiting_threads(t_table *table)
{
	while (!get_bool(&t_table->table_mutex, &t_table->threads_ready))
		;
}
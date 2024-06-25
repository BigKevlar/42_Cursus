/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:06:02 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/26 00:38:44 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_write(t_philo *philo, char *action)
{
	if ((philo->table->meals_limit == -1 || philo->meals_counter < philo->table->meals_limit) && !philo->table->is_dead)
	{
		printf("[%lu ms] philo nº%ld %s.\n", get_time(), philo->id, action);
		return (0);
	}
	return (1);
}

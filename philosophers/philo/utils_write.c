/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:06:02 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/24 21:48:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_write(t_philo *philo, char *action)
{
	if (philo->meals_counter != philo->table->meals_limit)
	{
		printf("[%lu ms] philo nº%ld %s.\n", get_time(), philo->id, action);
		return (0);
	}
	return (1);
}

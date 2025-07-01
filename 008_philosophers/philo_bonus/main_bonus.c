/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/26 06:12:47 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table	*table;

	table = ft_calloc((sizeof(t_table)), 1);
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
			return (free(table), 0);
		if (check_int(av))
			return (free(table), 0);
		if (table_init(ac, av, table) || philo_init(table))
		{
			the_end(table);
			return (0);
		}
		if (table->philo_num == 1)
			only_one_philo(table->philos);
		else
			start_game(table);
	}
	the_end(table);
	printf(PURPLE "PROGRAM FINISHED\n" END);
	return (0);
}

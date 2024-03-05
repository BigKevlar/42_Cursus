/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/05 22:20:50 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*data;
	int		c;
	int		len;

	data = NULL;
	c = 0;
	len = 0;
	checking_args ();
	init_stack


	
	while (av[c] != '\0')
		len++;
	data->stack_a = ft_calloc(len * sizeof(long));
	data->size_a = len;
	if (!data)
		args_error();
}

/*
Pseudocódigo de "Radix_Sort":
--------------------------------------------------------------------------------
Como este proyecto es avanzado daré por sabida algunas cosas e ire al grano.
Empezaremos por declarar una variante tipo t_stack,

*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/04 13:21:09 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av) // RADIX_SORT
{
	t_stack	*data;
	int		c;

	data = NULL;
	c = 0;
	if ((ac == 1) || (ac == 2 && !av[1][0]))
		args_error();
	else if (av == 2)
		av = ft_split_v2(av[1], ' ');
	while(av[c] != '\0')
		c++;
	data->stack_a = ft_calloc(c * sizeof(long));
}

/*
	create_stack_a(&a, av + 1);
	if (check_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			alg_sort_3(&a);
		else
			alg_sort_stacks(&a, &b);
	}
	final_free(&a);
	return (0);
*/
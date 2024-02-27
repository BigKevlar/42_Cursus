/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/27 19:36:02 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if ((ac == 1) || (ac == 2 && !av[1][0]))
		args_error();
	else if (av == 2)
		av = ft_split_v2(av[1], ' ');
	create_stack_a(&a, av + 1);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			
		else if (stack_len(a) == 3)

		else
			sort_stack(&a, &b);
	}
}

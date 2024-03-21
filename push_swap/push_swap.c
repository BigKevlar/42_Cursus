/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/21 19:58:07 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s;

	parse_args(ac, av);
	s = ft_calloc(1, sizeof(t_stack));
	if (!s)
		error_and_free (s, "Error");
	init_stacks(ac, av, s);
	join_args(ac, av, s);
	join_data(s);
	duplicates(s);
	create_index(s);
	if (is_sorted(s))
		free_stack(s);
	else if (s->size_a == 2 && s->data_a[0] > s->data_a[1])
		swap("sa", s->data_a, s->size_a);
	else if (s->size_a == 3)
		sort_3_args(s);
	else if (s->size_a >= 4 && s->size_a <= 5)
		sort_4_or_5_args(s);
	else
		radix_sort(s);
	free_stack(s);
	return (0);
}

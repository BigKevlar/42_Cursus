/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/11 13:50:06 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*s;

	check_args(ac, av);
	s = malloc(sizeof(t_stack));
	if (s == NULL)
		error_and_free (s, "ERROR, fallo de argumentos.");
	init_stacks(ac, av, s);
	join_args(ac, av, s);
	analize_numbers(s);
	duplicates(s);
	if (!is_sorted(s))
	{
		create_index(s);
		if (s->size_a == 2 && s->data_a[0] > s->data_a[1])
			swap("sa", s->data_a, s->size_a);
		else if (s->size_a == 3)
			sort_three_elements(s);
		else if (s->size_a >= 4 && s->size_a <= 5)
			sort_four_to_five_elements(s);
		else
			radix_sort(s);
	}
	free_stack(s);
	return (0);
}

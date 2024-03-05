/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/04 17:34:15 by jmartos-         ###   ########.fr       */
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
	while (av[c] != '\0')
		c++;
	data->stack_a = ft_calloc(c * sizeof(long));
	data->size_a = c;
	if (!data)
		args_error();
}

int	main(int argc, char **argv)
{
	initialize_stacks(argc, argv, s);
	join_args(argc, argv, s);
	parse_numbers(s);
	exit_if_sorted_or_has_duplicate(s, 0);
	create_index(s);
	if (s->a_size == 2 && s->a[0] > s->a[1])
		swap("sa", s->a, s->a_size);
	else if (s->a_size == 3)
		sort_three_elements(s);
	else if (s->a_size >= 4 && s->a_size <= 5)
		sort_four_to_five_elements(s);
	else
		radix_sort(s);
	exit_if_sorted_or_has_duplicate(s, 1);
	free_and_exit_with_message(s, "Error\n");
	return (0);
}
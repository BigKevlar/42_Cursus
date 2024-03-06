/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:36 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/06 19:01:56 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stacks *s)
{
	int	c;

	c = 0;
	while (c < s->a_size - 1)
	{
		if (s->a[c] > s->a[c + 1])
			return (0);
		c++;
	}
	return (1);
}

void	sorted_or_duplicates(t_stacks *s)
{
	int min;
	int	c;

	min = 0;
	c = 0;
	while (min < s->a_size)
	{
		c = min + 1;
		while (c < s->a_size)
		{
			if (s->data_a[min] == s->data_a[c])
				error_and_free (s, "ERROR");
			c++;
		}
		min++;
	}
	if (is_sorted(s))
		free_stack (s);
    return ;
}

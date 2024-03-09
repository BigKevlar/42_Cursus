/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:36 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/09 18:43:37 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	int	c;

	c = 0;
	while (c < s->size_a - 1)
	{
		if (s->data_a[c] > s->data_a[c + 1])
			return (0);
		c++;
	}
	return (1);
}

void	sorted_or_duplicates(t_stack *s)
{
	int min;
	int	c;

	min = 0;
	c = 0;
	while (min < s->size_a)
	{
		c = min + 1;
		while (c < s->size_a)
		{
			if (s->data_a[min] == s->data_a[c])
				error_and_free (s, "ERROR en 'sorted_or_duplicates'.");
			c++;
		}
		min++;
	}
	if (is_sorted(s))
		free_stack (s);
	return ;
}

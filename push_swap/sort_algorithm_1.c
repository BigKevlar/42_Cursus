/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:36 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/14 17:20:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicates(t_stack *s)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (c1 < s->size_a)
	{
		c2 = c1 + 1;
		while (c2 < s->size_a)
		{
			if (s->data_a[c1] == s->data_a[c2])
				error_and_free (s, "ERROR en 'duplicates'.");
			c2++;
		}
		c1++;
	}
	return ;
}

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

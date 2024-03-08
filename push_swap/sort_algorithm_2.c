/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:36 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/08 20:06:57 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stack *s)
{
	if (s->data_a[2] != 2)
	{
		if (s->data_a[0] == 2)
			rotate(s->data_a, s->size_a, "up", "a");
		else
			rotate(s->data_a, s->size_a, "down", "a");
	}
	if (s->data_a[0] > s->data_a[1])
		swap("sa", s->data_a, s->size_a);
}

void	sort_four_to_five_elements(t_stack *s)
{
	while (s->size_b <= 1)
	{
		if (s->data_a[0] == 0 || s->data_a[0] == 1)
			push("pb", s);
		else
			rotate(s->data_a, s->size_a, "up", "a");
	}
	if (s->data_b[0] == 0)
		swap("sb", s->data_b, s->size_b);
	if (s->data_a[2] != 4)
	{
		if (s->data_a[0] == 4)
			rotate(s->data_a, s->size_a, "up", "a");
		else
			rotate(s->data_a, s->size_a, "down", "a");
	}
	if (s->data_a[0] > s->data_a[1])
		swap("sa", s->data_a, s->size_a);
	push("pa", s);
	push("pa", s);
}

static void	radix_sort_stack_b(t_stack *s, int size_b, int size_bit, int x)
{
	while (size_b-- && x <= size_bit && !is_sorted(s))
	{
		if (((s->data_b[0] >> x) & 1) == 0)
			rotate(s->data_b, s->size_b, "up", "b");
		else
			push("pa", s);
	}
	if (is_sorted(s))
		while (s->size_b != 0)
			push("pa", s);
}

void	radix_sort(t_stack *s)
{
	int	x;
	int	size_bit;
	int	size;

	size_bit = 0;
	size = s->size_a;
	while (size > 1 && ++size_bit)
		size /= 2;
	x = -1;
	while (++x <= size_bit)
	{
		size = s->size_a;
		while (size-- && !is_sorted(s))
		{
			if (((s->data_a[0] >> x) & 1) == 0)
				push("pb", s);
			else
				rotate(s->data_a, s->size_a, "up", "a");
		}
		radix_sort_stack_b(s, s->size_b, size_bit, x + 1);
	}
	while (s->size_b != 0)
		push("pa", s);
}

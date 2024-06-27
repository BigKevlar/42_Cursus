/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:26:12 by jmartos           #+#    #+#             */
/*   Updated: 2024/03/21 17:06:40 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ordena el stack_b.
static void	sorting_b(t_stack *s, int size_b, int size_bit, int bit)
{
	while ((size_b != 0) && (bit <= size_bit) && (!is_sorted(s)))
	{
		if (((s->data_b[0] >> bit) & 1) == 0)
			rotate("up", "b", s->data_b, s->size_b);
		else
			push("pa", s);
		size_b--;
	}
	if (is_sorted(s))
		while (s->size_b != 0)
			push("pa", s);
	return ;
}

// Ordena el stack_a usando el stack_b cuando recibe 6 argumentos o mas.
//		(ver libreta para descripcion detallada del funcionamiento).
void	radix_sort(t_stack *s)
{
	int	bit;
	int	bit_size;
	int	tmp;

	bit = -1;
	bit_size = 0;
	tmp = s->size_a;
	while ((tmp > 1) && (++bit_size))
		tmp /= 2;
	while (++bit <= bit_size)
	{
		tmp = s->size_a;
		while ((tmp-- != 0) && (!is_sorted(s)))
		{
			if (((s->data_a[0] >> bit) & 1) == 0)
				push("pb", s);
			else
				rotate("up", "a", s->data_a, s->size_a);
		}
		sorting_b(s, s->size_b, bit_size, bit + 1);
	}
	while (s->size_b != 0)
		push("pa", s);
	return ;
}

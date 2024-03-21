/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:32:36 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/21 13:58:25 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifica si los numeros son mayores en orden descendente.
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

// Esta funcion ordenará con 1 o 2 movimientos 3 index de 3 argumentos.
void	sort_3_args(t_stack *s)
{
	if (s->data_a[2] != 2)
	{
		if (s->data_a[0] == 2)
			rotate("up", "a", s->data_a, s->size_a);
		else
			rotate("down", "a", s->data_a, s->size_a);
	}
	if (s->data_a[0] > s->data_a[1])
		swap("sa", s->data_a, s->size_a);
	return ;
}

// Esta funcion ordenará 4 o 5 index de argumentos.
void	sort_4_or_5_args(t_stack *s)
{
	while (s->size_b <= 1)
	{
		if (s->data_a[0] == 0 || s->data_a[0] == 1)
		{
			push("pb", s);
			if (s->data_b[0] == 0)
				swap("sb", s->data_b, s->size_b);
		}
		else
			rotate("up", "a", s->data_a, s->size_a);
	}
	if (s->data_a[2] != 4)
		rotate("up", "a", s->data_a, s->size_a);
	if (s->data_a[0] > s->data_a[1])
		swap("sa", s->data_a, s->size_a);
	push("pa", s);
	push("pa", s);
}

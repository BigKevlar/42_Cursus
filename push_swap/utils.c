/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:14 by jmartos-          #+#    #+#             */
/*   Updated: 2024/02/28 19:46:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if ((stack->value) > (stack->next->value))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	alg_sort_3(t_stack **a);
//

void	alg_sort_all(t_stack **a, t_stack **b);
//

void	final_free(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*now;

	if (*stack == NULL)
		exit(0);
	now = *stack;
	while (now != NULL)
	{
		tmp = now->next;
		free(now);
		now = tmp;
	}
	*stack = NULL;
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_codes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:58:17 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/07 22:59:08 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	if (stack != NULL)
	{
		if (stack->args != NULL)
			free(stack->args);
		if (stack->data_a != NULL)
			free(stack->data_a);
		if (stack->data_b != NULL)
			free(stack->data_b);
		free(stack);
		stack = NULL;
	}
	exit (1);
}

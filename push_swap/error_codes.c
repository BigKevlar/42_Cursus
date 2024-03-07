/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/07 22:59:09 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_free(t_stack *stack, char *message)
{
	if (message)
		ft_printf("%s\n", message);
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

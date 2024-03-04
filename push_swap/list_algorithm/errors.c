/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/28 19:37:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_error(void)
{
	ft_printf("%s\n", "ERROR, FALLO EN ARGUMENTOS!");
	exit(0);
}

void	stack_error(t_stack **stack)
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
	ft_printf("%s\n", "ERROR, FALLO EN STACK!");
	exit(0);
}

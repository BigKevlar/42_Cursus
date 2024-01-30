/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/01/30 19:47:03 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_A;
	t_stack	*stack_B;
	int		stack_size;
	int		c;

	c = 1; /* El contador lo vamos a iniciar en 1 para que minimo recibamos 1 numero por argumentos. */
	stack_B = NULL; /* Iniciamos el stack_A sin nada (null). */
	stack_A = NULL; /* Iniciamos el stack_B sin nada (null). */
	while (ac > c) /* Condicionamos que minimo tengamos 1 argumento para meterlo en el stack_A. */
	{
		create_stack(av[c], &stack_A);
		c++;
	}
	if (is_duplicate(stack_A))
		error_exit(&stack_A, NULL);
	stack_size = get_stack_size(stack_A);
	get_index(stack_A, stack_size + 1);
	push_swap(&stack_A, &stack_B, stack_size);
	free_stack(&stack_A);
	free_stack(&stack_B);
	return (0);
}
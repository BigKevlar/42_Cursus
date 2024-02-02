/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/02 19:48:41 by kevlar           ###   ########.fr       */
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
	stack_A = NULL; /* Iniciamos el stack_A sin nada (null). */
	stack_B = NULL; /* Iniciamos el stack_B sin nada (null). */
	while (ac > c) /* Condicionamos que minimo tengamos 1 argumento para meterlo en el stack_A. */
	{
		creating_stack(av[c], &stack_A);
		c++;
	}
	if (ckeck_duplicates(stack_A))
		error_exit(&stack_A, NULL);
	stack_size = get_stack_size(stack_A);
	return (0);
}
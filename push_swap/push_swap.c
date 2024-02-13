/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/13 17:07:06 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	(void)ac;
	t_int *num1;
	t_int *num2;
	t_stack *all;
	
	num1 = malloc(1 * sizeof(t_int));
	all = malloc(1 * sizeof(t_list));
	num1->value = atoi(av[1]);
	ft_lstadd_back(&all->a, ft_lstnew(num1));
	num2 = all->a->content;
	printf("%ld\n", num2->value);
}


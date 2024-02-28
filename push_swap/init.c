/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:11:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/02/28 19:41:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(t_stack **a, char **av)
{
	int	number;
	int	c;

	c = 0;
	while (av[c] != '\0')
	{
		if (check_number(av[1]))
			stack_error(a);
		number = ft_atol(av[c]);
		if (is_duplicate(a, n))
			stack_error(a);
		if (number < INT_MIN || number > INT_MAX)
			stack_error(a);
		add_node(a, number);
		c++;
	}
	return ;
}

void	add_node(t_stack **a, int number)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!(a))
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = number;
	node->next = NULL;
	return ;
}

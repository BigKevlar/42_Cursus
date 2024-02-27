/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:26:14 by jmartos-          #+#    #+#             */
/*   Updated: 2024/02/27 20:40:05 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	t_stack	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;
}
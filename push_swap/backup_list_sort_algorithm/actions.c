/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:54:19 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/04 17:32:24 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	first = *head;
	second = (*head)->next;
	if (!first || !second)
		return ;
	first->prev = second;
	first->next = second->next;
	second->prev = NULL;
	second->next = first;
	*head = second;
	return ;
}

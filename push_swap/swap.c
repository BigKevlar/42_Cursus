/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:07:12 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/28 18:14:19 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (swap a) Intercambia los dos primero nodos del stack a e imprime la orden.
void	sa(t_stack_node	**a)
{
	swap(a);
	ft_printf("sa\n");
	return ;
}

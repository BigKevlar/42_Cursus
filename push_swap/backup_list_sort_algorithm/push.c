/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:12:54 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/29 18:07:11 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pa\n");
	return ;
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pb\n");
	return ;
}

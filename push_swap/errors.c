/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/27 20:35:55 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	args_error(void)
{
	ft_printf("%s\n", "ERROR, FALLO EN ARGUMENTOS!");
	exit(0);
}

void	free_error(t_stack **stack)
{
	free_stack(stack);
	ft_printf("%s\n", "ERROR, FALLO EN STACK!");
	exit(0);
}
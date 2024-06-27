/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:32 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/20 22:01:19 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Intercambia los dos primeros elementos del stack ("sa" o "sb").
void	swap(char *msg, int *data, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	ft_printf("%s\n", msg);
	tmp = data[0];
	data[0] = data[1];
	data[1] = tmp;
}

// Si recibe "pa" empuja el stack_a hacia abajo y cuela el primero de b.
// Si recibe "pb" empuja el stack_b hacia abajo y cuela el primero de a.
void	push(char *msg, t_stack *s)
{
	int	tmp;

	if (ft_strncmp(msg, "pa", 3) == 0)
	{
		if (s->size_b <= 0)
			return ;
		tmp = s->data_b[0];
		ft_memmove(s->data_a + 1, s->data_a, sizeof(int) * s->size_a);
		s->size_a++;
		s->data_a[0] = tmp;
		ft_memmove(s->data_b, s->data_b + 1, sizeof(int) * s->size_b);
		s->size_b--;
	}
	else if (ft_strncmp(msg, "pb", 3) == 0)
	{
		if (s->size_a <= 0)
			return ;
		tmp = s->data_a[0];
		ft_memmove(s->data_b + 1, s->data_b, sizeof(int) * s->size_b);
		s->data_b[0] = tmp;
		s->size_a--;
		ft_memmove(s->data_a, s->data_a + 1, sizeof(int) * s->size_a);
		s->size_b++;
	}
	ft_printf("%s\n", msg);
}

// "r" = direction "up" (y en data y size recibe "a" o "b"):
//		desplaza hacia arriba el stack, y el primer elemento pasa al final.
// "rr" = direction "down" (y en data y size recibe "a" o "b"):
//		desplaza hacia abajo el stack, y el ultimo elemento pasa al principio.
void	rotate(char *direction, char *msg, int *data, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	if (ft_strncmp(direction, "up", 2) == 0)
	{
		tmp = data[0];
		ft_memmove(data, data + 1, sizeof(int) * (size - 1));
		data[size - 1] = tmp;
		ft_printf("%s", "r");
	}
	else if (ft_strncmp(direction, "down", 4) == 0)
	{
		tmp = data[size - 1];
		ft_memmove(data + 1, data, sizeof(int) * (size - 1));
		data[0] = tmp;
		ft_printf("%s", "rr");
	}
	ft_printf("%s\n", msg);
}

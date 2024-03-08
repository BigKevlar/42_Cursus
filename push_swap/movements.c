/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:05:32 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/08 20:13:57 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *int_str, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = int_str[0];
	int_str[0] = int_str[1];
	int_str[1] = tmp;
	ft_printf("%s", str);
}

void	push(char *str, t_stack *s)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->size_b <= 0)
			return ;
		tmp = s->data_b[0];
		ft_memmove(s->data_a + 1, s->data_a, sizeof(int) * s->size_a);
		s->data_a[0] = tmp;
		s->size_b--;
		ft_memmove(s->data_b, s->data_b + 1, sizeof(int) * s->size_b);
		s->size_a++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
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
	ft_putendl_fd(str, 1);
}

void	rotate(int *int_str, int size, char *direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (ft_strncmp(direction, "up", 5) == 0)
	{
		tmp = int_str[0];
		ft_memmove(int_str, int_str + 1, sizeof(int) * (size - 1));
		int_str[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = int_str[size - 1];
		ft_memmove(int_str + 1, int_str, sizeof(int) * (size - 1));
		int_str[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}

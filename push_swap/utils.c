/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:48:55 by jmartos           #+#    #+#             */
/*   Updated: 2024/03/20 00:00:06 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Crea un "indice de ordenacion temporal" para cada valor del stack.
void	create_index(t_stack *s)
{
	int		c1;
	int		c2;
	int		pos;
	int		*tmp;

	tmp = (int *)ft_calloc(s->size_a, sizeof(int));
	if (tmp == NULL)
		error_and_free (s, "ERROR en 'create_index'.");
	c1 = 0;
	while (c1 < s->size_a)
	{
		pos = 0;
		c2 = -1;
		while (++c2 < s->size_a)
			if (s->data_a[c1] > s->data_a[c2])
				pos++;
		tmp[c1] = pos;
		c1++;
	}
	c1 = s->size_a;
	while (c1--)
		s->data_a[c1] = tmp[c1];
	free(tmp);
	return ;
}

// Lo mismo que "atoi" pero teniendo en cuenta los INT_MAX e INT_MIN.
int	ft_atol(char *str, t_stack *s)
{
	int		c;
	long	num;
	int		sign;

	c = 0;
	num = 0;
	sign = 1;
	while (str[c] == ' ' || (str[c] >= '\t' && str[c] <= '\r'))
		c++;
	if (str[c] == '+' || str[c] == '-')
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9' && str[c] != '\0')
	{
		num = num * 10 + (str[c] - '0');
		if (num > INT_MAX || (num * sign) < INT_MIN)
			error_and_free(s, "Error en 'ft_atol'.");
		c++;
	}
	return ((int)num * sign);
}

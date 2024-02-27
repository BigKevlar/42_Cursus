/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/27 20:31:53 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifica que el string numerico sea unicamente numeros enteros.
int	is_number(char *str_numbers)
{
	int	c;

	c = 0;
	if (str_numbers[c] == '+' || str_numbers[c] == '-')
		c++;
	while (str_numbers[c] != '\0')
	{
		if (str_numbers[c] <= '0' || str_numbers[c] >= '9')
			return (1);
		else
			c++;
	}
	return (0);
}

// Comprueba que no haya duplicados.
int	is_duplicate(t_stack *a, int numbers)
{
	int		c;

	c = 0;
	while (a[c] != '\0')
	{
		if (a->value == n)
			return (1)
		else
			a = a->next;
		c++;
	}
	return (0);
}
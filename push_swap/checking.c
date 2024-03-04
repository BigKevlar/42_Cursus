/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/04 18:52:48 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifica que el string numerico sea unicamente numeros enteros.
int	check_number(char *str_numbers)
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

// Comprueba numeros duplicados.
int	check_duplicate(t_stack *a, int numbers)
{
	int	c;

	c = 0;
	while (a[c] != '\0')
	{
		if (a->value == n)
			return (1);
		else
			a = a->next;
		c++;
	}
	return (0);
}

void	checking_args(int ac, char **av)
{
	if ((ac == 1) || (ac == 2 && !av[1][0]))
		args_error();
	else if (av == 2)
		av = ft_split_v2(av[1], ' '); //MODIFICAR SPLIT???
	check_number();
	check_duplicate ();
}

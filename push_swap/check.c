/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/26 16:50:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Verifica que el string numerico sea unicamente numeros validos.
int	is_number(char *str_numbers)
{
	int	c;

	c = 0;
	if (str_numbers[c] == '+' || str_numbers[c] == '-')
		c++;
	while (str_numbers[c] != '\0')
	{
		if (str_numbers[c] <= '0' || str_numbers[c] >= '9')
			return (0);
		else
			c++;
	}
	return (1);
}

// Comprueba que no haya duplicados.
int	is_duplicate(char **str_numbers)
{
	int		c;
	char	*numbers;

	c = 0;
	numbers = str_numbers[1];
	while (numbers[c] != '\0')
	{
		if (ft_atol(numbers + c) > INT_MAX || ft_atol(numbers + c) < INT_MIN)
			return (0);
		if (numbers[c + 1] == numbers[c])
			return (0);
		else
			c++;
	}
	return (1);
}

// Verifica la entrada de argumentos con las funciones anteriores.
char	**validation(int ac, char **av)
{
	char	**args;
	int		c;

	c = 0;
	args = NULL;
	if (ac == 1)
		exit(0);
	else if (ac == 2 && av[1][0] == '\0')
		args_error();
	else if (ac > 2)
		args = av + 1;
	else if (ac == 2)
	{
		if (av[1] == NULL)
			args_error();
		else
			args = ft_split(av[1], ' ');
	}
	if (!is_number(args[c]))
		args_error();
	if (!is_duplicate(args))
		args_error();
	return (args);
}

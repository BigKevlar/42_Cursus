/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/19 20:53:27 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// VERIFICA QUE EL ARRAY DE CARACTERES NUMERICOS SEA DE POSITIVOS Y NEGATIVOS.
int	ft_is_number(char *numbers)
{
	int	c;

	c = 0;
	if (numbers[c] == '+' || numbers[c] == '-')
		c++;
	while (numbers[c] != '\0')
	{
		if (numbers[c] <= '0' || numbers[c] >= '9')
			return (0);
		else
			c++;
	}
	return (1);
}

// COMPARA TODOS LOS CARACTERES NUMERICOS PARA COMPROBAR POSIBLES DUPLICADOS.
int	ft_is_duplicate(char **numbers)
{
	int		c;

	c = 0;
	while (numbers[c] != '\0')
	{
		if (ft_atol(numbers[c]) > INT_MAX || ft_atol(numbers[c]) < INT_MIN)
			return (0);
		if (numbers[c + 1] == numbers[c])
			return (0);
		else
			c++;
	}
	return (1);
}

// VALIDA LA ENTRADA DE LOS ARGUMENTOS AL MAIN.
char	**validation(int ac, char **av)
{
	char	**args;
	int		c;

	c = 0;
	args = NULL;
	if (ac == 1)
		exit(0);
	else if (ac == 2 && av[1][0] == '\0')
		ft_args_error();
	else if (ac > 2)
		args = av + 1;
	else if (ac == 2)
	{
		if (av[1] == NULL)
			ft_args_error();
		else
			args = ft_split(av[1], ' ');
	}
	if (!ft_is_number(args[c]))
		ft_args_error();
	if (!ft_is_duplicate(args[c]))
		ft_args_error();
	return (args);
}
/*
int	*args_to_int(char **args);
{
	
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/05 22:20:48 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Comprueba numeros enteros.
static void	check_number(char **n)
{
	int	c;

	c = 0;
	if (n[c] == '+' || n[c] == '-')
		c++;
	while (n[c] != '\0')
	{
		if (n[c] <= '0' && n[c] >= '9')
			error_and_free (NULL, "ERROR");
		else
			c++;
	}
	return ;
}

// Comprueba numeros duplicados.
static void	check_duplicate(char **n)
{
	int	c1;
	int	c2;
	int tmp;

	c1 = 0;
	c2 = 1;
	while (n[c1] != '\0')
	{
		tmp = n[c1];
		while (n[c2] != '\0')
		{
			if (tmp == n[c2])
				error_and_free (NULL, "ERROR");
			c2++;
		}	
		c1++;
	}
	return ;
}

void	checking_args(int ac, char **av)
{
	int	c;
	char **args;

	c = 1;
	if ((ac == 1) || (ac == 2 && !av[1][0]))
		args_error();
	else if (ac == 2)
	{
		args = ft_split_v2(av[1], ' '); //MODIFICAR SPLIT???
		args = ft_atol(args);
		check_number(args);
		check_duplicate (args);
	}
	return ;
}

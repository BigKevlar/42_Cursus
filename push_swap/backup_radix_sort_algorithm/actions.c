/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/06 15:02:47 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// (funcion statica) Comprueba numeros enteros.
static void	check_number(char **n)
{
	int	c;

	c = 0;
	if (n[c] == '+' || n[c] == '-')
		c++;
	while (n[c] != '\0')
	{
		if (n[c] <= '0' && n[c] >= '9')
			error_and_free (NULL, "ERROR, numeros no validos");
		else
			c++;
	}
	return ;
}

// (funcion statica) Comprueba numeros duplicados.
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
				error_and_free (NULL, "ERROR, numeros duplicados");
			c2++;
		}	
		c1++;
	}
	return ;
}

static void	join_args(int ac, char **av, t_stacks *stack)
{
	char	*tmp1;
	char	*tmp2;
	int		c;

	tmp1 = NULL;
	tmp2 = NULL;
	c = 1;
	while (ac > c)
	{
		tmp1 = ft_strjoin(tmp2, av[c]); // reservamos espacio igual a tmp2 + av[c].
		if (tmp1 == NULL)
			error_and_free (NULL, "ERROR, fallo de argumentos");
		if (c != ac - 1)
		{
			tmp2 = ft_strjoin(tmp1, " ");
			if (tmp2 == NULL)
			{
				free(tmp1);
				error_and_free (NULL, "ERROR, fallo de argumentos");
			}
			free(tmp1);
			tmp1 = tmp2;
		}
		c++;
	}
	stack->args = ft_strdup(tmp1);
	if (stack->args == NULL)
		error_and_free (NULL, "ERROR");
	free(tmp1);
	return ;
}

// (funcion princial) Comprueba los argumentos y los mete en el stack.
void	init_stack_checked(int ac, char **av)
{
	char **args;

	if ((ac == 1) || (ac == 2 && !av[1][0]))
		error_and_free (NULL, "ERROR, argumentos incorrectos");
	args = ft_split_v2(av[1], ' '); //MODIFICAR SPLIT???
	if (!args)
		error_and_free (NULL, "ERROR, fallo en argumentos");
	check_number(args);
	check_duplicate (args);
	join_args(ac, args, a)
	return ;
}

//
//
//
//
//
//

static void	validate_arguments(int ac, char **av)
{
	int	c1;
	int	c2;

	c1 = 1;
	if (ac < 2)
		error_and_free (NULL, "ERROR\n");
	while (c1 < ac)
	{
		c2 = 0;
		if (!av[c1][0] || (av[c1][0] && av[c1][0] == ' '))
			error_and_free (NULL, "ERROR\n");
		while (av[c1][c2] != '\0')
		{
			if ((!(ft_isdigit(av[c1][c2])) && (av[c1][c2] != ' ')
			&& (av[c1][c2] != '-' && av[c1][c2] != '+' && av[c1][c2] != ' '))
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == ' ')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == ' '))
				error_and_free (NULL, "ERROR\n");
			c2++;
		}
		c++;
	}
	return ;
}

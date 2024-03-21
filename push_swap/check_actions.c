/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/21 18:21:00 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Chequea el de numero de argumentos y la sintaxis de los mismos.
void	parse_args(int ac, char **av)
{
	int	c1;
	int	c2;

	if ((ac == 1) || (ac == 2 && av[1] == NULL))
		error_and_free (NULL, "ERROR en 'parse_args'.");
	c1 = 1;
	while (c1 < ac)
	{
		if ((av[c1][0] == ' ') || av[c1][0] == '\0')
			error_and_free (NULL, "ERROR en 'parse_args'.");
		c2 = 0;
		while (av[c1][c2] != '\0')
		{
			if ((!(ft_isdigit(av[c1][c2])) && (av[c1][c2] != '-'
				&& av[c1][c2] != '+' && av[c1][c2] != ' '))
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == ' ')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == ' '))
				error_and_free (NULL, "ERROR en 'parse_args'.");
			c2++;
		}
		c1++;
	}
	return ;
}

// Inicializa los stacks (data_a y data_b) contando los argumentos.
void	init_stacks(int ac, char **av, t_stack *s)
{
	int	c;

	c = 0;
	s->size_a = 0;
	while (ac > 1)
	{
		if (ft_word_counter(av[c + 1], ' '))
			s->size_a += ft_word_counter(av[c + 1], ' ');
		else
			s->size_a += 1;
		c++;
		ac--;
	}
	s->data_a = (int *)ft_calloc(s->size_a, sizeof(s->data_a));
	if (s->data_a == NULL)
		error_and_free (s, "ERROR en 'init_stacks'.");
	s->data_b = (int *)ft_calloc(s->size_a, sizeof(s->data_b));
	if (s->data_b == NULL)
		error_and_free (s, "ERROR en 'init_stacks'.");
	return ;
}

// Inserta los argumentos en la lista de la estructura.
void	join_args(int ac, char **av, t_stack *s)
{
	int		c;
	char	*tmp1;
	char	*tmp2;

	c = 1;
	tmp2 = ft_strdup("");
	while (c < ac && av[c] != NULL)
	{
		tmp1 = ft_strjoin(tmp2, av[c]);
		if (tmp1 == NULL)
			error_and_free (s, "ERROR en 'join_args'.");
		tmp2 = tmp1;
		if (c < ac - 1)
		{
			tmp1 = ft_strjoin(tmp2, " ");
			if (tmp1 == NULL)
				error_and_free (s, "ERROR en 'join_args'.");
			tmp2 = tmp1;
		}
		c++;
	}
	s->args = ft_strdup(tmp2);
	if (s->args == NULL)
		error_and_free (s, "ERROR en 'join_args'.");
	return ;
}

// Pasamos los argumentos a long (int) y los metemos en el stack a.
void	join_data(t_stack *s)
{
	int		c;
	char	**tmp;

	c = 0;
	tmp = ft_split(s->args, ' ');
	if (tmp == NULL)
		error_and_free (s, "ERROR en 'join_data'.");
	while (tmp[c] != NULL)
	{
		s->data_a[c] = ft_atol(tmp[c], s);
		c++;
	}
	free(tmp);
	return ;
}

// Una funcion simple para verificar que no hay numeros duplicados.
void	duplicates(t_stack *s)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (c1 < s->size_a)
	{
		c2 = c1 + 1;
		while (c2 < s->size_a)
		{
			if (s->data_a[c1] == s->data_a[c2])
				error_and_free (s, "ERROR en 'duplicates'.");
			c2++;
		}
		c1++;
	}
	return ;
}

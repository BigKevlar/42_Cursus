/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/10 19:16:29 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int ac, char **av)
{
	int	c1;
	int	c2;

	if ((ac == 1) || (ac == 2 && av[1][0] == '\0'))
		error_and_free (NULL, "ERROR en 'check_args'.");
	c1 = 1;
	while (ac > c1)
	{
		c2 = 0;
		if ((av[c1][0] == ' ') || av[c1][0] == '\0')
			error_and_free (NULL, "ERROR en 'check_args'.");
		while (av[c1][c2] != '\0')
		{
			if ((!(ft_isdigit(av[c1][c2])) && (av[c1][c2] != ' ')
			&& (av[c1][c2] != '-' && av[c1][c2] != '+' && av[c1][c2] != ' '))
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == ' ')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == ' '))
				error_and_free (NULL, "ERROR en 'check_args'.");
			c2++;
		}
		c1++;
	}
	return ;
}

void	init_stacks(int ac, char **av, t_stack *s)
{
	int	c;

	c = 0;
	s->size_a = 0;
	s->size_b = 0;
	while (ac > 1)
	{
		if (ft_word_counter(av[c + 1], ' ') > 0)
			s->size_a += ft_word_counter(av[c + 1], ' ');
		else
			s->size_a++;
		c++;
		ac--;
	}
	s->data_a = (int *)malloc(s->size_a * sizeof(long));
	if (s->data_a == NULL)
		error_and_free (s, "ERROR en 'init_stacks'.");
	s->data_b = (int *)malloc(s->size_b * sizeof(long));
	if (s->data_b == NULL)
		error_and_free (s, "ERROR en 'init_stacks'.");
	return ;
}

void	join_args(int ac, char **av, t_stack *s)
{
	char	*tmp1;
	char	*tmp2;
	int		c;

	c = 1;
	tmp1 = ft_strdup("");
	tmp2 = ft_strdup("");
	while (ac > c && av[c] != NULL)
	{
		tmp1 = ft_strjoin(tmp2, av[c]);
		if (c != ac - 1)
		{
			free(tmp2);
			tmp2 = ft_strjoin(tmp1, " ");
			if (tmp1 == NULL)
			{
				free(tmp1);
				error_and_free (s, "ERROR en 'join_args'.");
			}
			free(tmp1);
			tmp1 = tmp2;
		}
		c++;
	}
	s->args = ft_strdup(tmp2);
	if (s->args == NULL)
		error_and_free (s, "ERROR en 'join_args'.");
	free(tmp1);
	free(tmp2);
}

void	analize_numbers(t_stack *s)
{
	int		c;
	char	**tmp;

	c = 0;
	tmp = ft_split(s->args, ' ');
	if (tmp == NULL)
		error_and_free (s, "ERROR en 'analize_numbers'.");
	while (tmp[c] != NULL && tmp[c][0] != '\0')
	{
		s->data_a[c] = ft_atol(tmp[c + 1], s);
		free(tmp[c - 1]);
	}
	free(tmp);
}

void	create_index(t_stack *s)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(s->size_a * sizeof(int));
	if (new_a == NULL)
		error_and_free (s, "ERROR en 'create_index'.");
	i = -1;
	while (++i < s->size_a)
	{
		k = 0;
		j = -1;
		while (++j < s->size_a)
			if (s->data_a[i] > s->data_a[j])
				k++;
		new_a[i] = k;
	}
	i = s->size_a;
	while (i--)
		s->data_a[i] = new_a[i];
	free(new_a);
}

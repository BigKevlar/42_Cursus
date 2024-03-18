/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/18 14:35:34 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Chequea el de numero de argumentos y la sintaxis de los mismos.
void	check_args(int ac, char **av)
{
	int	c1;
	int	c2;

	if ((ac == 1) || (ac == 2 && av[1] == NULL))
		error_and_free (NULL, "ERROR en 'check_args'.");
	c1 = 1;
	while (c1 < ac)
	{
		if ((av[c1][0] == ' ') || av[c1][0] == '\0')
			error_and_free (NULL, "ERROR en 'check_args'.");
		c2 = 0;
		while (av[c1][c2] != '\0')
		{
			if ((!(ft_isdigit(av[c1][c2]))
			&& (av[c1][c2] != '-' && av[c1][c2] != '+' && av[c1][c2] != ' '))
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '-' && av[c1][c2 + 1] == ' ')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == '\0')
			|| (av[c1][c2] == '+' && av[c1][c2 + 1] == ' '))
				error_and_free (NULL, "ERROR en 'check_args'.");
			c2++;
		}
		c1++;
	}
	return ;
}

// cuanthccjhcjchjgchgcchgch
void	init_stacks(int ac, char **av, t_stack *s)
{
	int	c;

	c = 0;
	s->size_a = 0;
	s->size_b = 0;
	while (ac > 1)
	{
		if (ft_word_counter(av[c + 1], ' '))
			s->size_a += ft_word_counter(av[c + 1], ' ');
		else
			s->size_a++;
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

void	join_args(int ac, char **av, t_stack *s)
{
	char	*tmp1;
	char	*tmp2;
	int		c;

	c = 1;
	tmp2 = ft_strdup("");
	while (c < ac && av[c] != NULL)
	{
		tmp1 = ft_strjoin(tmp2, av[c]);
		if (tmp1 == NULL)
			free(tmp2);
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
	free(tmp2);
	if (s->args == NULL)
		error_and_free (s, "ERROR en 'join_args'.");
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
		s->data_a[c] = ft_atol(tmp[c], s);
		c++;
	}
	c = 0;
	while (tmp[c] != NULL)
	{
		free(tmp[c]);
		c++;
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

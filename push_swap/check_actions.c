/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:23:20 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/07 23:07:16 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int ac, char **av)
{
	int	c1; //1
	int	c2; //1

	if ((ac == 1) || (ac == 2 && av[1][0] = '\0')) //2
		error_and_free (NULL, "ERROR\n");
	c1 = 1;
	while (ac > c1) //3
	{
		c2 = 0;
		if ((av[c1][0] == ' ') || av[c1][0] == '\0') //4
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
		c1++;
	}
	return ;
}

/*
Pseudocódigo:
********************************************************************************

1- Iniciamo dos variables contador, una para iterar sobre los argumentos y otra
para iterar sobre los caracteres de cada argumento.

2- Vemos si hay al menos un argumento o si hay un argumento vacio, y si es asi
llamamos a "error_and_free" para liberar memoria y salir del programa dando
un mensaje de error.

3- Si se pasan "bien" los argumentos, se itera sobre cada argumento con un bucle
para recorrer cada caracter y validarlo (por eso lo iniamos a 0 en cada vuelta):

4- Se comprueba si el primer carácter del argumento. Si esta vacio o es un
espacio llamamos a "error_and_free".

5- Si es valido el argumento, ahora chequeamos cada caracter del mismo con otro
bucle. Iteramos cada carácter de la siguiente manera: 

6- 


*/

void	init_stacks(int ac, char **av, t_stack *s)
{
	int	c;

	c = 0;
	s->size_a = 0;
	s->size_b = 0;
	while (ac > 1)
	{
		if (ft_word_counter(av[c + 1], ' ') > 0)
			s->size_a += ft_count_words(av[c + 1], ' ');
		else
			s->size_a++;
		c++;
		ac--;
	}
	s->data_a = (long *)malloc(s->size_a * sizeof(long));
	if (s->data_a == NULL)
		error_and_free (s, "ERROR\n");
	s->data_b = (long *)malloc(s->size_b * sizeof(long));
	if (s->data_b == NULL)
		error_and_free (s, "ERROR\n");
	return ;
}

void	join_args(int ac, char **av, t_stack *s)
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
			error_and_free (s, "ERROR, fallo de argumentos");
		if (c != ac - 1)
		{
			tmp2 = ft_strjoin(tmp1, " ");
			if (tmp2 == NULL)
			{
				free(tmp1);
				error_and_free (s, "ERROR, fallo de argumentos");
			}
			free(tmp1);
			tmp1 = tmp2;
		}
		c++;
	}
	s->args = ft_strdup(tmp1);
	if (s->args == NULL)
		error_and_free (s, "ERROR");
	free(tmp1);
	return ;
}

void	analize_numbers(t_stack *s)
{
	int		c;
	char	**tmp;

	c = 0;
	tmp = ft_split(s->args, ' ');
	if (tmp == NULL)
		error_and_free (s, "ERROR");
	while (tmp[c] != NULL)
	{
		
		s->data_a[c] = ft_atol(tmp[c], s);
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

	new_a = malloc(s->size_a * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit_with_message(s, "Error\n");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:31:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/18 20:35:55 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_isnumber(char *numbers)
{
	int	c;

	c = 0;
	while (numbers[c] != '\0')
	{
		if (numbers[c] <)		
	}
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack *b;
	int		c;

	a = NULL;
	b = NULL;
	c = 0;
	if ((ac == 1) || (ac == 2 && !av[1][0]))
	{
		ft_printf("%s\n", "ERROR, argumentos vacios o inexistentes!");
		return (1);
	}
	else if (ac == 2)
	{
		av = split(av[1], ' ');
		if (ft_isnumber(av[1]))
			return (0);
		
	}
	return (0);
}

/*
int	main(int ac, char **av)
{
	(void)ac;
	t_int *num1;
	t_int *num2;
	t_stack_test *all;
	
	num1 = malloc(1 * sizeof(t_int));
	all = malloc(1 * sizeof(t_list));
	num1->value = atoi(av[1]);
	ft_lstadd_back(&all->a, ft_lstnew(num1));
	num2 = all->a->content;
	printf("%ld\n", num2->value);
}
*/
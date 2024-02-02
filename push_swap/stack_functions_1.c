/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:36:48 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/02 19:48:42 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_numbers(char *param)
{
	int	c;

	c = 0;
	if(param[c] == '+' || param[c] == '-') && (ft_strlen(param) > 1 /* Si encuentra un simbolo de + o -, y es */)
		c++;
}

void	creating_stack(char *av, t_stack **stack_a)
{
	char		**param;
	long int	num;
	int			c;

	param = ft_split(av, ' '); /* Vamos a separar cada numero que nos entre con ft_split, que tomara un espacio como delimitador.*/
	c = 0;
	while (param[c] != '\0')
	{
		if (input_is_correct(param[c]))
		{
			num = ft_atoi(param[c]);
			if (num > INT_MAX || num < INT_MIN)
				error_exit(stack_a, NULL);
			stack_add(stack_a, stack_new(num));
		}
		else
			error_exit(NULL, NULL);
		free(param[c]);
		c++;
	}
	free(param);
}

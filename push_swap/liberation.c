/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:02:06 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/18 13:45:40 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Escribe un error, libera los punteros del stack y el mismo, y finaliza.
void	error_and_free(t_stack *s, char *error)
{
	if (error)
		ft_printf("%s\n", error);
	if (s != NULL)
	{
		if (s->args != NULL)
			free(s->args);
		if (s->data_a != NULL)
			free(s->data_a);
		if (s->data_b != NULL)
			free(s->data_b);	
		free(s);
		s = NULL;
	}
	exit (1);
}

// Libera los punteros del stack y el mismo, y finaliza.
void	free_stack(t_stack *s)
{
	if (s != NULL)
	{
		if (s->args != NULL)
			free(s->args);
		if (s->data_a != NULL)
			free(s->data_a);
		if (s->data_b != NULL)
			free(s->data_b);
		free(s);
		s = NULL;
	}
	exit (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/21 12:29:31 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libreria 42 jmartos-
# include "libft/includes/libft.h"

// Estructura de los stacks.
typedef struct s_stack
{
	char	*args;
	int		*data_a;
	int		*data_b;
	int		size_a;
	int		size_b;
}			t_stack;

/****************/
/* LIBERATION.C */
/****************/

void		error_and_free(t_stack *s, char *error);
void		free_stack(t_stack *s);

/*******************/
/* CHECK_ACTIONS.C */
/*******************/

void		parse_args(int ac, char **av);
void		init_stacks(int ac, char **av, t_stack *s);
void		join_args(int ac, char **av, t_stack *s);
void		join_data(t_stack *s);
void		duplicates(t_stack *s);

/********************/
/* SORT_ACTIONS.C */
/********************/

int			is_sorted(t_stack *s);
void		sort_3_args(t_stack *s);
void		sort_4_or_5_args(t_stack *s);

/********************/
/* RADIX_SORT.C */
/********************/

void		radix_sort(t_stack *s);

/***************/
/* MOVEMENTS.C */
/***************/

void		swap(char *msg, int *data, int size);
void		push(char *msg, t_stack *s);
void		rotate(char *direction, char *msg, int *data, int size);

/***********/
/* UTILS.C */
/***********/

void		create_index(t_stack *s);
int			ft_atol(char *str, t_stack *s);

#endif

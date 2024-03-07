/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/07 23:10:32 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h" /* Libreria 42 jmartos- */
# include <stdlib.h> /* malloc y free */
# include <stdbool.h> /* Para imprimir los nombres de las funciones */
# include <limits.h> /* INT_MIN y INT_MAX */

typedef struct s_stack
{
	char	*args;
	int		*data_a;
	int		*data_b;
	int		size_a;
	int 	size_b;
}			t_stack;
//
void		error_and_free(t_stack *stack, char *message);
//
void		free_stack(t_stack *stack);
//
void		check_args(int ac, char **av);
void		init_stacks(int ac, char **av, t_stack *s);
void		join_args(int ac, char **av, t_stack *s);
void		analize_numbers(t_stack *s);
void		create_index(t_stack *s);
//
void		sorted_or_duplicates(t_stack *s);
//
void		sort_three_elements(t_stack *s);
void		sort_four_to_five_elements(t_stack *s);
void		radix_sort(t_stack *s);
//
void		swap(char *str, int *array, int size);
void		push(char *str, t_stack *s);
void		rotate(int *array, int size, char *direction, char *list);

#endif
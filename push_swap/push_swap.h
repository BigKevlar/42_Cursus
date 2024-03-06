/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/06 19:32:31 by kevlar           ###   ########.fr       */
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
void	error_and_free(t_stack stack, char *message);
//
void	free_stack(t_stack stack);
//
void	ckeck_args(int ac, char **av);
void	init_stacks(int ac, char **av, t_stacks *s);
void	join_args(int ac, char **av, t_stacks *s);
void	analize_numbers(t_stacks *s);
void	create_index(t_stacks *s);
//
static int	is_sorted(t_stacks *s);
void	sorted_or_duplicates(t_stacks *s);
//
void	sort_three_elements(t_stacks *s);
void	sort_four_to_five_elements(t_stacks *s);
static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j);
void	radix_sort(t_stacks *s);

#endif
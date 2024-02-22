/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/22 14:36:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h" /* Libreria 42 jmartos- */
# include <stdlib.h> /* malloc */
# include <limits.h> /* INT_MIN y INT_MAX */

typedef struct s_stack
{
	int				int_args;
	int				*stack_a;
	int				*stack_b;
	int				size_a;
	int				size_b;
	int				len;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void	ft_args_error(void);
int		ft_is_number(char *numbers);
int		ft_is_duplicate(char **numbers);
char	**validation(int ac, char **av);

#endif

/*
typedef struct s_stack_test
{
	char				**str;
	t_list *a;
	t_list *b;
} t_stack_test;

typedef struct s_int
{
	long value;
	
} t_int;
*/
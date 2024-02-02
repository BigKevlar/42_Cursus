/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/02 19:48:40 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h" /* Libreria 42 jmartos- */
# include <stdio.h> /* printf */
# include <stddef.h> /* size_t */
# include <stdlib.h> /* atoi, malloc, free */
# include <limits.h> /* ¿? */

typedef struct s_stack
{
	int				value;
	int				pos;
	int				action;
	struct s_stack	*next;
}					t_stack;

/* Propotipo de funciones para iniciar y comprobar el stack. */
t_stack	*creating_stack(int value)
funcion (check_stack)
funcion (sort_stack)
/**/
funcion (do_swap)
funcion (do_push)
funcion (do_rotate)
funcion (do_reverse_rotate)

#endif
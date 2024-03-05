/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/03/05 22:20:50 by jmartos          ###   ########.fr       */
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
	int	*data_a;
	int	*data_b;
	int	size_a;
	int size_b;
}		t_stack;

/********************/
/* ERROR (error.c) */
/********************/

void	error_and_free(t_stack stack, char *error);

/****************************/
/* COMPROBACIONES (check.c) */
/****************************/

int		check_number(char *numbers);
int		check_duplicate(char **numbers);
void	checking_args(int ac, char **av);

/************************/
/* CREAR STACK (init.c) */
/************************/

t_stack	create_stack_a(int number);

/************************/
/* CREAR NODOS (init.c) */
/************************/

/**************************/
/* ORDENAR STACK (init.c) */
/**************************/

/*********************/
/* ACCIONES (init.c) */
/*********************/

static void	 swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/******************************/
/* FUNCIONES VARIAS (utils.c) */
/******************************/



#endif

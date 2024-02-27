/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/27 19:36:50 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h" /* Libreria 42 jmartos- */
# include <stdbool.h> /* Para imprimir los nombres de las funciones */
# include <limits.h> /* INT_MIN y INT_MAX */

typedef struct s_stack
{
	int				value; /* el numero */
	int				index; /* la posicion en el stack */
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/**********************/
/* ERRORES (errors.c) */
/**********************/

void	args_error(void);

/****************************/
/* COMPROBACIONES (check.c) */
/****************************/

int		is_number(char *numbers);
int		is_duplicate(char **numbers);
char	**validation(int ac, char **av);

/************************/
/* CREAR STACK (init.c) */
/************************/

t_stack	create_stack(int number);

/************************/
/* CREAR NODOS (init.c) */
/************************/

/************************/
/* ORDENAR STACK (init.c) */
/************************/

/******************************/
/* FUNCIONES VARIAS (utils.c) */
/******************************/



#endif
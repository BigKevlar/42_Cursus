/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:32:16 by kevlar            #+#    #+#             */
/*   Updated: 2024/02/26 16:25:17 by jmartos-         ###   ########.fr       */
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

/***************/
/*   ERRORES   */
/***************/

void	args_error(void);

/********************/
/*   VALIDACIONES   */
/********************/

int		is_number(char *numbers);
int		is_duplicate(char **numbers);
char	**validation(int ac, char **av);

/*******************/
/*   CREAR STACK   */
/*******************/

t_stack	create_stack(int number);
/*******************/
/*   CREAR NODOS   */
/*******************/

/************************/
/*   FUNCIONES VARIAS   */
/************************/

ft_split();

#endif
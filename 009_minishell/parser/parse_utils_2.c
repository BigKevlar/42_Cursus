/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:05:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 13:51:59 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Procesa la parte de un array que está encerrada entre comillas dobles.
*/
char	*process_dq(char *prompt, int *pos)
{
	int		w_pos;
	int		dq_counter;
	char	*aux;

	w_pos = 0;
	dq_counter = 0;
	aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));
	while (prompt[*pos] && dq_counter < 2)
	{
		if (prompt[*pos] == '\"')
			dq_counter++;
		aux[w_pos++] = prompt[*pos];
		(*pos)++;
	}
	return (aux);
}

/*
	Procesa la parte de un array que está encerrada entre comillas simples.
*/
char	*process_sq(char *prompt, int *pos)
{
	int		w_pos;
	int		sq_counter;
	char	*aux;

	w_pos = 0;
	sq_counter = 0;
	aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));
	while (prompt[*pos] && sq_counter < 2)
	{
		if (prompt[*pos] == '\'')
			sq_counter++;
		if (prompt[*pos] == '$')
			aux[w_pos++] = (char)1;
		else
			aux[w_pos++] = prompt[*pos];
		(*pos)++;
	}
	return (aux);
}

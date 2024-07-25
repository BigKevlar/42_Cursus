/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:54 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/23 13:26:00 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Parseamos el prompt para comprobar errorres del estilo:
	
		- Comillas mas cerradas (check_quotes).
		- Que el primer caracter no sea un pipe (check_first_pipe).
		- Que las pipes sean las permitidas y las redirecciones esten bien
			abiertas y cerradas (validating_pipes_reds):
*/
int	check_cmd(t_shell *shell)
{
	int	pos;
	int	state;

	pos = 0;
	state = NO_QUOTE;
	while (shell->prompt[pos])
	{
		if (shell->prompt[pos] == '\"' || shell->prompt[pos] == '\'')
			state = check_quotes(shell->prompt[pos], state);
		pos++;
	}
	if (state != NO_QUOTE)
	{
		ft_printf(RED"ERROR! (check_cmd)\n"NC);
		exit(EXIT_FAILURE);
	}
	if (check_first_pipe(shell->prompt) == 0)
		return (0);
	else
		return (validating_pipes_reds(shell->prompt));
}

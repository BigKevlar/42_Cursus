/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validating_pipes_reds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:14:59 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 22:47:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	handle_pipe_red(char c, t_pipe_red *value, char *prompt, int *pos)
{
	if (c == '|')
	{
		if (value->pipe == 1 || !check_first_pipe(prompt))
			return (0);
		set_pipe_red(value, 1);
	}
	else if (c == '<' || c == '>')
	{
		if (value->red == 1 || !check_mixes(prompt, pos))
			return (0);
		set_pipe_red(value, 2);
	}
	else
		set_pipe_red(value, 3);
	return (1);
}

int	update_quote_state(char c, int quote_state)
{
	return (check_quotes(c, quote_state));
}

int	validating_pipes_reds(char *prompt)
{
	int			pos;
	int			quote_state;
	t_pipe_red	value;

	pos = 0;
	quote_state = NO_QUOTE;
	init_pipe_red(&value);
	while (prompt[pos])
	{
		quote_state = update_quote_state(prompt[pos], quote_state);
		if (quote_state == NO_QUOTE)
		{
			if (!handle_pipe_red(prompt[pos], &value, prompt, &pos))
				return (0);
		}
		pos++;
	}
	return (check_last_pipe_red(prompt));
}

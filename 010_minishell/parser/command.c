/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:54 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/19 22:02:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		printf(RED"ERROR! (check_cmd)\n"NC);
		return (-1);
	}
	if (check_first_pipe(shell->prompt) == 0)
		return (0);
	else
		return (validating_pipes_reds(shell->prompt));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 23:23:23 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/03 14:20:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_dq(int state)
{
	if (state == NO_QUOTE)
		return (DQ_OPEN);
	else if (state == DQ_OPEN)
		return (NO_QUOTE);
	else
		return (state);
}

static int	is_sq(int state)
{
	if (state == NO_QUOTE)
		return (SQ_OPEN);
	else if (state == SQ_OPEN)
		return (NO_QUOTE);
	else
		return (state);
}

int	check_quotes(char quote, int state)
{
	int	new_state;

	new_state = state;
	if (quote == '\"')
		new_state = is_dq(state);
	else if (quote == '\'')
		new_state = is_sq(state);
	return (new_state);
}

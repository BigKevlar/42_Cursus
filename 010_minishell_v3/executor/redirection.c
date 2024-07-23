/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:50:24 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 20:55:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_output_redirection(char **prompt, t_shell *shell, int i)
{
	int	j;
	int	is_command_before;

	is_command_before = 0;
	if (i == 0 || prompt[i - 1] == NULL)
		is_command_before = 1;
	apply_outfile(prompt, shell, i);
	if (is_command_before == 1)
	{
		prompt[i] = ft_strdup("cat");
		i++;
	}
	j = i;
	while (prompt[j] != NULL)
	{
		prompt[j] = prompt[j + 1];
		j++;
	}
}

void	handle_input_redirection(char **prompt, t_shell *shell, int i)
{
	int	j;

	if (i == 0 || prompt[i - 1] == NULL)
		shell->exec_signal = 1;
	apply_infile(prompt, shell, i);
	j = i;
	while (prompt[j] != NULL)
	{
		prompt[j] = prompt[j + 1];
		j++;
	}
}

void	apply_redirections(char **prompt, t_shell *shell)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (ft_strcmp(prompt[i], ">") == 0 || ft_strcmp(prompt[i], ">>") == 0)
			handle_output_redirection(prompt, shell, i);
		else if (ft_strcmp(prompt[i], "<") == 0 || ft_strcmp(prompt[i],
				"<<") == 0)
			handle_input_redirection(prompt, shell, i);
		else
			i++;
	}
}

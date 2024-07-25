/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:25:24 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 11:19:37 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	pipe_counter(char **str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 1;
	while (str[i])
	{
		if (strcmp(str[i], "|") == 0)
			cont++;
		i++;
	}
	return (cont);
}

void	handle_inred(char **split, int *i, t_cmd *cmd, int *in_cont)
{
	cmd->incmd[(*in_cont)++] = strdup(split[*i]);
	(*i)++;
	if (split[*i])
		cmd->incmd[(*in_cont)++] = strdup(split[(*i)++]);
}

void	handle_outred(char **split, int *i, t_cmd *cmd, int *out_cont)
{
	cmd->outcmd[(*out_cont)++] = strdup(split[*i]);
	(*i)++;
	if (split[*i])
		cmd->outcmd[(*out_cont)++] = strdup(split[(*i)++]);
}

void	parse_command(char **split_cmd, int *index, t_cmd *cmd_struct)
{
	int	arg_cont;
	int	in_cont;
	int	out_cont;

	arg_cont = 0;
	in_cont = 0;
	out_cont = 0;
	while (split_cmd[*index] && strcmp(split_cmd[*index], "|") != 0)
	{
		if (strcmp(split_cmd[*index], "<") == 0
			|| strcmp(split_cmd[*index], "<<") == 0)
			handle_inred(split_cmd, index, cmd_struct, &in_cont);
		else if (strcmp(split_cmd[*index], ">") == 0
			|| strcmp(split_cmd[*index], ">>") == 0)
			handle_outred(split_cmd, index, cmd_struct, &out_cont);
		else
		{
			if (cmd_struct->cmd == NULL)
				cmd_struct->cmd = strdup(split_cmd[*index]);
			else
				cmd_struct->args[arg_cont++] = strdup(split_cmd[*index]);
			(*index)++;
		}
	}
}

void	executor_split(t_shell *shell)
{
	t_cmd	**cmds;
	int		i;
	int		cmd_index;
	int		pipe_cont;

	i = 0;
	cmd_index = 0;
	pipe_cont = pipe_counter(shell->split_cmd);
	cmds = ft_calloc(pipe_cont + 1, sizeof(t_cmd *));
	allocate_memory(cmds, shell->split_cmd);
	while (shell->split_cmd[i])
	{
		parse_command(shell->split_cmd, &i, cmds[cmd_index]);
		if (shell->split_cmd[i] && strcmp(shell->split_cmd[i], "|") == 0)
			i++;
		cmd_index++;
	}
	i = 0;
	if (shell->cmds)
	{
		while (shell->cmds[i])
			free_cmd(shell->cmds[i++]);
		free(shell->cmds);
	}
	shell->cmds = cmds;
}

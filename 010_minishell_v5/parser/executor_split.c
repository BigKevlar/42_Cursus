/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:25:24 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/24 16:40:31 by rguerrer         ###   ########.fr       */
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

void	allocate_memory_args(t_cmd *cmds, char **split_cmd)
{
	int	arg_count;
	int	i;

	arg_count = 0;
	i = 0;
	while (split_cmd[i] && strcmp(split_cmd[i], "|") != 0)
	{
		if (i > 0)
		{
			if (strcmp(split_cmd[i], ">") == 0 || strcmp(split_cmd[i],
					">>") == 0 || strcmp(split_cmd[i], "<") == 0)
			{
				i += 2;
			}
			else
			{
				arg_count++;
				i++;
			}
		}
		else
			i++;
	}
	cmds->args = ft_calloc(arg_count + 1, sizeof(char *));
}

void	allocate_memory_in(t_cmd *cmds, char **split_cmd)
{
	int	in_count;
	int	i;

	in_count = 0;
	i = 0;
	while (split_cmd[i] && strcmp(split_cmd[i], "|") != 0)
	{
		if (strcmp(split_cmd[i], "<") == 0 || strcmp(split_cmd[i], "<<") == 0)
		{
			in_count++;
			i++;
			if (split_cmd[i])
			{
				in_count++;
				i++;
			}
		}
		else
			i++;
	}
	cmds->incmd = ft_calloc(in_count + 1, sizeof(char *));
}

void	allocate_memory_out(t_cmd *cmds, char **split_cmd)
{
	int	out_count;
	int	i;

	out_count = 0;
	i = 0;
	while (split_cmd[i] && strcmp(split_cmd[i], "|") != 0)
	{
		if (strcmp(split_cmd[i], ">") == 0 || strcmp(split_cmd[i], ">>") == 0)
		{
			out_count++;
			i++;
			if (split_cmd[i])
			{
				out_count++;
				i++;
			}
		}
		else
			i++;
	}
	cmds->outcmd = ft_calloc(out_count + 1, sizeof(char *));
}

void	allocate_memory(t_cmd **cmds, char **split_cmd)
{
	int	i;
	int	cmd_count;

	cmd_count = 0;
	cmd_count = pipe_counter(split_cmd);
	i = 0;
	while (i < cmd_count)
	{
		cmds[i] = (t_cmd *)malloc(sizeof(t_cmd));
		if (!cmds[i])
			return ;
		cmds[i]->cmd = NULL;
		allocate_memory_args(cmds[i], split_cmd);
		allocate_memory_in(cmds[i], split_cmd);
		allocate_memory_out(cmds[i], split_cmd);
		i++;
	}
}

void	parse_command(char **split_cmd, int *index, t_cmd *cmd_struct)
{
	int	arg_count;
	int	in_count;
	int	out_count;

	arg_count = 0;
	in_count = 0;
	out_count = 0;
	while (split_cmd[*index] && strcmp(split_cmd[*index], "|") != 0)
	{
		if (strcmp(split_cmd[*index], "<") == 0 || strcmp(split_cmd[*index],
				"<<") == 0)
		{
			cmd_struct->incmd[in_count++] = strdup(split_cmd[*index]);
			(*index)++;
			if (split_cmd[*index])
			{
				cmd_struct->incmd[in_count++] = strdup(split_cmd[*index]);
				(*index)++;
			}
		}
		else if (strcmp(split_cmd[*index], ">") == 0
			|| strcmp(split_cmd[*index], ">>") == 0)
		{
			cmd_struct->outcmd[out_count++] = strdup(split_cmd[*index]);
			(*index)++;
			if (split_cmd[*index])
			{
				cmd_struct->outcmd[out_count++] = strdup(split_cmd[*index]);
				(*index)++;
			}
		}
		else
		{
			if (cmd_struct->cmd == NULL)
			{
				cmd_struct->cmd = strdup(split_cmd[*index]);
			}
			else
			{
				cmd_struct->args[arg_count++] = strdup(split_cmd[*index]);
			}
			(*index)++;
		}
	}
}

void	executor_split(t_shell *shell)
{
	t_cmd **cmds;
	int i = 0;
	int cmd_index = 0;
	int pipe_count = pipe_counter(shell->split_cmd);

	cmds = (t_cmd **)malloc(sizeof(t_cmd *) * (pipe_count + 1));
	if (!cmds)
		return ;
	allocate_memory(cmds, shell->split_cmd);
	while (shell->split_cmd[i])
	{
		parse_command(shell->split_cmd, &i, cmds[cmd_index]);
		if (shell->split_cmd[i] && strcmp(shell->split_cmd[i], "|") == 0)
			i++;
		cmd_index++;
	}
	cmds[pipe_count] = NULL;
	shell->cmds = cmds;
}

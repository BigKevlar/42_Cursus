/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_split_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 11:47:49 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_cmd(t_cmd *cmd)
{
	free(cmd->cmd);
	ft_strd_free(cmd->args);
	ft_strd_free(cmd->incmd);
	ft_strd_free(cmd->outcmd);
	free(cmd);
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
		cmds[i] = ft_calloc(1, sizeof(t_cmd));
		cmds[i]->cmd = NULL;
		allocate_memory_args(cmds[i], split_cmd);
		allocate_memory_in(cmds[i], split_cmd);
		allocate_memory_out(cmds[i], split_cmd);
		i++;
	}
}

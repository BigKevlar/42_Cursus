/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 11:37:43 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion ejecuta un comando de sistema. */

char	*get_cmd_path(char *cmd, char *bin)
{
	char	*path;

	path = malloc(ft_strlen(bin) + ft_strlen(cmd) + 2);
	if (path == NULL)
		return (NULL);
	ft_strlcpy(path, bin, ft_strlen(bin) + 1);
	ft_strlcat(path, "/", ft_strlen(bin) + 2);
	ft_strlcat(path, cmd, ft_strlen(bin) + ft_strlen(cmd) + 2);
	if (access(path, F_OK) == 0)
		return (path);
	else
	{
		free(path);
		return (NULL);
	}
}

static char	**get_bin_paths(t_shell *shell)
{
	int	x;

	x = 0;
	while (shell->env && shell->env[x])
	{
		if (ft_strncmp(shell->env[x], "PATH=", 5) == 0)
			return (ft_split(shell->env[x] + 5, ':'));
		x++;
	}
	return (NULL);
}

static void	find_cmd_path(t_shell *shell, t_cmd *cmd, char **bin)
{
	int	x;

	x = 0;
	shell->cmd_path = get_cmd_path(cmd->cmd, bin[x]);
	while (cmd->cmd && bin[++x] && shell->cmd_path == NULL)
		shell->cmd_path = get_cmd_path(cmd->cmd, bin[x]);
}

void	execute_bin(t_shell *shell, t_cmd **cmds, int i)
{
	char	**bin;

	bin = get_bin_paths(shell);
	if (!cmds[i]->cmd || !bin)
	{
		shell->g_status = 1;
		error_msg(cmds[i]->cmd);
		return ;
	}
	find_cmd_path(shell, cmds[i], bin);
	if (shell->cmd_path != NULL)
		exc(shell->cmd_path, cmds, shell, i);
	else
		exc(cmds[i]->cmd, cmds, shell, i);
	ft_strd_free(bin);
	free(shell->cmd_path);
}

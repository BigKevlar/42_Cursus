/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 22:01:32 by rguerrer         ###   ########.fr       */
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
/*
void	exc(char *path, t_cmd **cmd, t_shell *shell, int i)
{
	pid_t	pid;
	int		status;
	char	**exc;

	exc = ft_undo(cmd, i);
	pid = fork();
	if (pid == 0)
	{
		if (shell->fdin > 2)
		{
			dup2(shell->fdin, STDIN_FILENO);
			close(shell->fdin);
		}
		if (shell->fdout > 2)
		{
			dup2(shell->fdout, STDOUT_FILENO);
			close(shell->fdout);
		}
		if (ft_strchr(path, '/') != NULL)
			execve(path, exc, shell->env);
		shell->g_status = error_msg(path);
		exit(shell->g_status);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->g_status = WEXITSTATUS(status);
	else
		shell->g_status = 1;
	if (shell->fdin > 2)
		close(shell->fdin);
	if (shell->fdout > 2)
		close(shell->fdout);
}

*/

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
/**
void	execute_bin(t_shell *shell, t_cmd **cmds, int i)
{
	int		x;
	char	**bin;

	x = 0;
	while (shell->env && shell->env[x])
	{
		if (ft_strncmp(shell->env[x], "PATH=", 5) == 0)
			break ;
		x++;
	}
	if (shell->env[x] == NULL)
	{
		error_msg(cmds[i]->cmd);
		return ;
	}
	bin = ft_split(shell->env[x], ':');
	if (!cmds[i]->cmd && !bin)
	{
		shell->g_status = 1;
		return ;
	}
	x = 1;
	shell->cmd_path = get_cmd_path(cmds[i]->cmd, bin[0] + 5);
	while (cmds[i]->cmd && bin[x] && shell->cmd_path == NULL)
		shell->cmd_path = get_cmd_path(cmds[i]->cmd, bin[x++]);
	if (shell->cmd_path != NULL)
		exc(shell->cmd_path, cmds, shell, i);
	else
		exc(cmds[i]->cmd, cmds, shell, i);
	return (ft_strd_free(bin), free(shell->cmd_path));
}
*/
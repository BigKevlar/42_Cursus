/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 02:42:51 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion ejecuta un comando de sistema. */

char	**ft_undo(t_cmd **cmds, int i)
{
	char	**exc;
	int		x;

	x = 0;
	while (cmds[i]->args != NULL && cmds[i]->args[x] != NULL)
		x++;
	exc = calloc(x + 1, sizeof(char *));
	x = 0;
	exc[x] = ft_strdup(cmds[i]->cmd);
	x++;
	if (cmds[i]->args != NULL)
	{
		while (cmds[i]->args[x-1] != NULL && cmds[i]->args != NULL)
		{
			exc[x] = ft_strdup(cmds[i]->args[x-1]);
			x++;
		}
	}
	exc[x] = NULL;
	return (exc);
}

int	error_msg(char *path)
{
	DIR	*dir;
	int	status;

	status = 0;
	dir = opendir(path);
	ft_putstr_fd(path, STDERR_FILENO);
	if (ft_strchr(path, '/') == NULL)
		ft_putstr_fd(": command not found", STDERR_FILENO);
	else if (access(path, F_OK) == -1)
		ft_putstr_fd(": No such file or directory", 2);
	else if (dir != NULL)
	{
		ft_putstr_fd(": is a directory", 2);
		closedir(dir);
	}
	else if (access(path, X_OK) == -1)
		ft_putstr_fd(": Permission denied", 2);
	if (ft_strchr(path, '/') == NULL || (dir == NULL))
		status = 127;
	else
		status = 126;
	if (dir != NULL)
		closedir(dir);
	ft_putchar_fd('\n', 2);
	return (status);
}

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

void	exc(char *path, t_cmd **cmd, t_shell *shell, int i)
{
	pid_t	pid;
	int		status;
	char	**exc;

	exc = ft_undo(cmd, i);
	pid = fork();
	if (pid == 0)
	{
		if (shell->fdin > 2) {
			dup2(shell->fdin, STDIN_FILENO);
			close(shell->fdin);
		}
		if (shell->fdout > 2) {
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
		shell->g_status = 1;
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


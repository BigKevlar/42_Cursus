/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/23 10:26:48 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion ejecuta un comando de sistema. */

int	error_msg(char *cmd)
{
	DIR	*dir;
	int	status;

	dir = opendir(cmd);
	if (ft_strchr(cmd, '/') == NULL)
		ft_putstr_fd("zsh: command not found: ", 2);
	else if (access(cmd, F_OK) == -1)
		ft_putstr_fd("zsh: no such file or directory: ", 2);
	else if (dir != NULL)
	{
		ft_putstr_fd("zsh: is a directory: ", 2);
		closedir(dir);
	}
	else if (access(cmd, X_OK) == -1)
		ft_putstr_fd("zsh: permission denied: ", 2);
	if (ft_strchr(cmd, '/') == NULL || (dir == NULL))
		status = 127;
	else
		status = 126;
	ft_putstr_fd(cmd, 2);
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

int	exc(char *path, char **cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
			execve(path, cmd, shell->env);
		shell->g_status = error_msg(path);
		exit(shell->g_status);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			shell->g_status = WEXITSTATUS(status);
		else
			shell->g_status = 1;
	}
	return (shell->g_status);
}

int	execute_bin(t_shell *shell, char **cmd)
{
	int		i;
	char	**bin;
	int		status;

	i = 0;
	while (shell->env && shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (shell->env[i] == NULL)
		return (exc(cmd[0], cmd, shell));
	bin = ft_split(shell->env[i], ':');
	if (!cmd[0] && !bin)
		return (1);
	i = 1;
	shell->cmd_path = get_cmd_path(cmd[0], bin[0] + 5);
	while (cmd[0] && bin[i] && shell->cmd_path == NULL)
		shell->cmd_path = get_cmd_path(cmd[0], bin[i++]);
	if (shell->cmd_path != NULL)
		status = exc(shell->cmd_path, cmd, shell);
	else
		status = exc(cmd[0], cmd, shell);
	return (ft_strd_free(bin), free(shell->cmd_path), status);
}

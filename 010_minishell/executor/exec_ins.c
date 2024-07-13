/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:43:22 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/10 12:51:57 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion ejecuta un comando de sistema. */

void	error_msg(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
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

int	exc(char *path, char **cmd, char **env, t_shell *shell)
{
	shell->pid = fork();
	if (shell->pid == 0)
	{
		if (ft_strchr(path, '/') != NULL)
			execve(path, cmd, env);
		error_msg(path);
		exit(1);
	}
	else
		waitpid(shell->pid, 0, 0);
	return (0);
}

int	execute_ins(t_shell *shell, t_cmd *cmd)
{
	int		i;
	char	**bin;

	i = 0;
	while (shell->env && shell->env[i])
	{
		if (ft_strncmp(shell->env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (shell->env[i] == NULL)
	{
		exc(cmd->full_cmd[0], cmd->full_cmd, shell->env, shell);
		return (cmd->g_status);
	}
	bin = ft_split(shell->env[i], ':');
	if (!cmd->full_cmd[0] && !bin)
		return (1);
	i = 1;
	cmd->cmd_path = get_cmd_path(cmd->full_cmd[0], bin[0] + 5);
	while (cmd->full_cmd[0] && bin[i] && cmd->cmd_path == NULL)
		cmd->cmd_path = get_cmd_path(cmd->full_cmd[0], bin[i++]);
	if (cmd->cmd_path != NULL)
		cmd->g_status = exc(cmd->cmd_path, cmd->full_cmd, shell->env, shell);
	else
		cmd->g_status = exc(cmd->full_cmd[0], cmd->full_cmd, shell->env, shell);
	// liberar memoria bin
	// liberar memoria utilizada
	return (cmd->g_status);
}

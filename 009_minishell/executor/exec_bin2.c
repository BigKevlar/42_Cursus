/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bin2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:05:48 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 11:14:39 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	handle_redirections(t_shell *shell)
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
}

static void	execute_child_process(char *path, char **exc, t_shell *shell)
{
	handle_redirections(shell);
	if (ft_strchr(path, '/') != NULL)
		execve(path, exc, shell->env);
	shell->g_status = error_msg(path);
	exit(shell->g_status);
}

void	exc(char *path, t_cmd **cmd, t_shell *shell, int i)
{
	pid_t	pid;
	int		status;
	char	**exc;

	exc = ft_undo(cmd, i);
	pid = fork();
	if (pid == 0)
		execute_child_process(path, exc, shell);
	waitpid(pid, &status, 0);
	shell->g_status = status;
	if (shell->fdin > 2)
		close(shell->fdin);
	if (shell->fdout > 2)
		close(shell->fdout);
	if (shell->g_status == 32512 || shell->g_status == 32256)
		shell->g_status /= 256;
	ft_strd_free(exc);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:58:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 21:20:17 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_pipe_error(t_shell *shell)
{
	ft_putstr_fd("zsh: pipe or fork failed\n", 2);
	shell->exec_signal = 1;
	shell->g_status = 1;
}

void	parent_process(t_shell *shell, int *prev_fd, int fd[2])
{
	waitpid(shell->pid, &shell->g_status, 0);
	close(fd[1]);
	if (*prev_fd != -1)
		close(*prev_fd);
}

void	apply_pipe(t_shell *shell, char **cmd, int *prev_fd)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (handle_pipe_error(shell));
	pid = fork();
	if (pid == -1)
		return (handle_pipe_error(shell));
	if (pid == 0)
	{
		if (*prev_fd != -1)
		{
			dup2(*prev_fd, STDIN_FILENO);
			close(*prev_fd);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		if (shell->exec_signal == 0)
			exec_choose(shell, cmd);
		exit(EXIT_SUCCESS);
	}
	else
		parent_process(shell, prev_fd, fd);
	*prev_fd = fd[0];
}

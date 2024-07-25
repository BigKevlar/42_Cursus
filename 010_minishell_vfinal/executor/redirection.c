/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:50:24 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:55:33 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	setup_redirections(t_shell *shell)
{
	shell->exec_signal = 0;
	shell->infile = dup(STDIN_FILENO);
	shell->outfile = dup(STDOUT_FILENO);
}

void	reset_redirections(t_shell *shell)
{
	dup2(shell->infile, STDIN_FILENO);
	dup2(shell->outfile, STDOUT_FILENO);
	close(shell->infile);
	close(shell->outfile);
}

void	apply_outfile(char **name, t_shell *shell, int i)
{
	if (shell->fdout > 2)
		close(shell->fdout);
	if (ft_strcmp(name[i], ">>") == 0)
		shell->fdout = open(name[i + 1], O_WRONLY | O_CREAT | O_APPEND,
				S_IRWXU);
	else
		shell->fdout = open(name[i + 1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd(name[i + 1], STDERR_FILENO);
		ft_putstr_fd(": no such file or directory\n", STDERR_FILENO);
		shell->exec_signal = 1;
		shell->g_status = 1;
	}
}

void	apply_infile(char **name, t_shell *shell, int i)
{
	if (shell->fdin > 2)
		close(shell->fdin);
	if (ft_strcmp(name[i], "<<") == 0)
		apply_heredoc(name[i + 1], shell);
	else
	{
		shell->fdin = open(name[i + 1], O_RDONLY);
		if (shell->fdin == -1)
		{
			ft_putstr_fd(name[i + 1], STDERR_FILENO);
			ft_putstr_fd(": no such file or directory\n", STDERR_FILENO);
			shell->exec_signal = 1;
			shell->g_status = 1;
		}
	}
}

void	apply_redirections(char **redir, t_shell *shell)
{
	int	j;

	j = 0;
	while (redir != NULL && redir[j] != NULL)
	{
		if (ft_strcmp(redir[j], ">") == 0 || ft_strcmp(redir[j], ">>") == 0)
			apply_outfile(redir, shell, j);
		else if (ft_strcmp(redir[j], "<") == 0 || ft_strcmp(redir[j],
				"<<") == 0)
			apply_infile(redir, shell, j);
		j++;
	}
}

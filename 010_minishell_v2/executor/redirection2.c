/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 21:23:38 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putchar_fd('\n', 2);
		shell->exec_signal = 1;
		shell->g_status = 1;
	}
	dup2(shell->fdout, STDOUT_FILENO);
}

void	apply_infile(char **name, t_shell *shell, int i)
{
	if (shell->fdin > 2)
		close(shell->fdin);
	if (ft_strcmp(name[i], "<<") == 0)
		apply_heredoc(name[i + 1], shell);
	else
	{
		shell->fdin = open(name[i + 1], O_RDONLY, S_IRWXU);
		if (shell->fdin == -1)
		{
			ft_putstr_fd("zsh: no such file or directory: ", 2);
			ft_putstr_fd(name[i + 1], 2);
			ft_putchar_fd('\n', 2);
			shell->exec_signal = 1;
			shell->g_status = 1;
		}
		dup2(shell->fdin, STDIN_FILENO);
	}
}

void	setup_redirections(t_shell *shell)
{
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

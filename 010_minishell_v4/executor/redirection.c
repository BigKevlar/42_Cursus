/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:50:24 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 01:20:40 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	apply_outfile(char **name, t_shell *shell)
{
	if (shell->fdout > 2)
		close(shell->fdout);
	if (ft_strcmp(name[0], ">>") == 0)
		shell->fdout = open(name[1], O_WRONLY | O_CREAT | O_APPEND,
				S_IRWXU);
	else
		shell->fdout = open(name[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	if (shell->fdout == -1)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 2);
		ft_putstr_fd(name[1], 2);
		ft_putchar_fd('\n', 2);
		shell->exec_signal = 1;
		shell->g_status = 1;
	}
	//dup2(shell->fdout, STDOUT_FILENO);
}

void	apply_infile(char **name, t_shell *shell)
{
	if (shell->fdin > 2)
		close(shell->fdin);
	if (ft_strcmp(name[0], "<<") == 0)
		apply_heredoc(name[1], shell);
	else
	{
		shell->fdin = open(name[1], O_RDONLY);
		if (shell->fdin == -1)
		{
			ft_putstr_fd("zsh: no such file or directory: ", 2);
			ft_putstr_fd(name[1], 2);
			ft_putchar_fd('\n', 2);
			shell->exec_signal = 1;
			shell->g_status = 1;
		}
		//dup2(shell->fdin, STDIN_FILENO);
	}
}

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

void	apply_redirections(char **redir, t_shell *shell)
{
	int	j;

	j = 0;
	while (redir != NULL && redir[j] != NULL)
	{
		if (ft_strcmp(redir[j], ">") == 0 || ft_strcmp(redir[j], ">>") == 0)
			apply_outfile(redir, shell);
		else if (ft_strcmp(redir[j], "<") == 0 || ft_strcmp(redir[j],
				"<<") == 0)
			apply_infile(redir, shell);
		j++;
	}
}

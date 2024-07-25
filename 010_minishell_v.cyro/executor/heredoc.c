/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:57:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 21:21:16 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	handle_heredoc_error(t_shell *shell)
{
	ft_putstr_fd("heredoc: error creating pipe\n", STDERR_FILENO);
	shell->exec_signal = 1;
	shell->g_status = 1;
}

void	apply_heredoc(char *delimiter, t_shell *shell)
{
	int		pipefd[2];
	char	*line;

	if (pipe(pipefd) == -1)
		return (handle_heredoc_error(shell));
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line || ft_strcmp(line, delimiter) == 0)
			break ;
		line[ft_strlen(line) - 1] = '\0';
		if (ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		line[ft_strlen(line)] = '\n';
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	close(pipefd[1]);
	shell->fdin = pipefd[0];
	dup2(shell->fdin, STDIN_FILENO);
}

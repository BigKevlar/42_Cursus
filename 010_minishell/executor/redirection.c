/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:37:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/10 12:43:24 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_outfile(char **name, t_cmd *cmds, int i)
{
	if (cmds->outfile)
		close(cmds->outfile);
	cmds->outfile = open(name[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmds->outfile < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		cmd->g_status = 1;
		return ;
	}
	dup2(cmds->outfile, STDOUT_FILENO);
}

void	get_infile(char **name, t_cmd *cmds, int i)
{
	if (cmds->infile)
		close(cmds->infile);
	cmds->infile = open(name[i + 1], O_RDONLY, S_IRWXU);
	if (cmds->infile < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(name[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		cmd->g_status = 1;
		return ;
	}
	dup2(cmds->infile, STDIN_FILENO);
}

void	get_pipe(t_cmd *cmds)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		if (pipefd[1] != STDOUT_FILENO)
			close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		close(pipefd[1]);
		execute(cmds->full_cmd, cmds->env);
		exit(cmds->g_status);
	}
	else
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
	}
}

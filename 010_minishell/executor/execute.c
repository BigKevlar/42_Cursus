/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 10:34:42 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void exclude_redirection(char **prompt)
{
	int	i;

	i = 0;
	while(prompt[i])
	{
		if (ft_strcmp(prompt[i], ">") == 0)
		{
			free(prompt[i]);
			prompt[i] = NULL;
		}
		i++;
	}
}

void	apply_redirections(char **prompt, t_shell *shell)
{
	int i;
	int j;
	int is_command_before;
	int x;

	i = 0;
	j = 0;
	is_command_before = 0;
	while (prompt[i])
	{
		x = 2;
		if (ft_strcmp(prompt[i], ">") == 0 || ft_strcmp(prompt[i], ">>") == 0)
		{
			if (i == 0 || prompt[i - 1] == NULL)
				is_command_before = 1;
			apply_outfile(prompt, shell, i);
			if (is_command_before == 1)
			{
				prompt[i] = ft_strdup("cat");
				i++;
				x = 1;
			}
			j = i;
			while(prompt[j] != NULL)
			{
				prompt[j] = prompt[j + x];
				j++;
			}
			is_command_before = 0;
		} 
		else if (ft_strcmp(prompt[i], "<") == 0 || ft_strcmp(prompt[i], "<<") == 0)
		{
			if (i == 0 || prompt[i - 1] == NULL)
				shell->exec_signal = 1;
			apply_infile(prompt, shell, i);
			j = i;
			while(prompt[j] != NULL)
			{
				prompt[j] = prompt[j + x];
				j++;
			}
		} 
		else
			i++;
	}
}

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_shell *shell, char **cmd)
{
	shell->g_status = 0;

	exclude_redirection(cmd);
	if (cmd && is_builtin(cmd[0]) == 1)
		execute_builtin(shell, cmd);
	else if (cmd)
		shell->g_status = execute_ins(shell, cmd);
	if (shell->pin > 0)
		close(shell->pin);
	if (shell->pout > 0)
		close(shell->pout);
	shell->pin = -1;
	shell->pout = -1;
}

void execute(t_shell *shell)
{
	char **cmd;
	int i = 0, j = 0, k = 0;
	int prev_fd = -1;

	shell->infile = dup(STDIN_FILENO);
	shell->outfile = dup(STDOUT_FILENO);
	while (shell->full_cmd[i] != NULL)
	{
		while (shell->full_cmd[i] != NULL && ft_strcmp(shell->full_cmd[i], "|") != 0)
			i++;
		cmd = ft_calloc(i - j + 1, sizeof(char *));
		if (cmd == NULL)
			return ;
		k = 0;
		while (k < i - j) 
		{
			cmd[k] = shell->full_cmd[j + k];
			k++;
		}
		cmd[k] = NULL;
		apply_redirections(cmd, shell);
		if (shell->full_cmd[i] != NULL)
			apply_pipe(shell, cmd, &prev_fd);
		else
		{
			if (prev_fd != -1)
			{
				dup2(prev_fd, STDIN_FILENO);
				close(prev_fd);
			}
			if (shell->exec_signal == 0)
				exec_choose(shell, cmd);
		}
		ft_strd_free(cmd);
		if (shell->full_cmd[i] != NULL)
			i++;
		j = i;
	}
	dup2(shell->infile, STDIN_FILENO);
	dup2(shell->outfile, STDOUT_FILENO);
	close(shell->infile);
	close(shell->outfile);
}

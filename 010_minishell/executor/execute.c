/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:57:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_cmd **cmds, t_shell *shell, int i)
{
	shell->g_status = 0;
	if (cmds[i]->cmd && is_builtin(cmds[i]->cmd) == 1)
		execute_builtin(shell, cmds, i);
	else if (cmds[i]->cmd)
		execute_bin(shell, cmds, i);
}

void	execute(t_cmd **cmds, t_shell *shell)
{
	int	i;

	i = 0;
	setup_redirections(shell);
	while (cmds[i] != NULL)
	{
		shell->fdnextin = -1;
		if (cmds[i + 1] != NULL)
			apply_pipe(shell);
		else
			shell->fdout = STDOUT_FILENO;
		apply_redirections(cmds[i]->incmd, shell);
		apply_redirections(cmds[i]->outcmd, shell);
		if (cmds[i]->cmd != NULL)
			exec_choose(cmds, shell, i);
		shell->fdin = shell->fdnextin;
		i++;
	}
	reset_env(shell, cmds);
	reset_redirections(shell);
}

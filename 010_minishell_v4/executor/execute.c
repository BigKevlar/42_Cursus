/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:37:06 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 02:46:20 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_undo_dim(char **cmd)
{
	int	i;
	int len;
	char *str;

	i = 0;
	while (cmd[i] != NULL)
	{	
		len += ft_strlen(cmd[i]) + 1;
		i++;
	}
	str = ft_calloc(len + i + 1, sizeof(char));
	i = 0;
	int pos = 0;
	while (cmd[i] != NULL)
	{
		strcpy(str + pos, cmd[i]);
		pos += ft_strlen(cmd[i]);
		str[pos] = ' ';
		pos++;
		i++;
	}
	str[len] = '\0';
	return (str);
}

/* Esta funcion comprueba si existe un builtin y escoje*/
void	exec_choose(t_cmd **cmds, t_shell *shell, int i)
{
	shell->g_status = 0;
	if (cmds[i]->cmd && is_builtin(cmds[i]->cmd) == 1)
		execute_builtin(shell, cmds, i);
	else if (cmds[i]->cmd)
		execute_bin(shell, cmds, i);
	if (shell->pin > 0)
		close(shell->pin);
	if (shell->pout > 0)
		close(shell->pout);
	shell->pin = -1;
	shell->pout = -1;
}

void	execute(t_cmd **cmds, t_shell *shell)
{
	int i;
	
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
		exec_choose(cmds, shell, i);
		shell->fdin = shell->fdnextin;
		i++;
	}
	reset_env(shell);
	reset_redirections(shell);
}

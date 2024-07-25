/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:54:02 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 20:56:08 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* Esta funcion elige el builtin a ejecutar. */

void	execute_builtin(t_shell *shell, t_cmd **cmds, int i)
{
	char	*builtins;

	builtins = cmds[i]->cmd;
	if (!ft_strcmp(builtins, "echo"))
		ft_echo(cmds[i]->args, shell);
	else if (!ft_strcmp(builtins, "cd"))
		ft_cd(cmds[i]->args, shell);
	else if (!ft_strcmp(builtins, "env"))
		ft_env(shell, cmds[i]->args);
	else if (!ft_strcmp(builtins, "exit"))
		ft_exit(cmds[i]->args, shell);
	else if (!ft_strcmp(builtins, "export"))
		ft_export(cmds[i]->args, shell);
	else if (!ft_strcmp(builtins, "unset"))
		ft_unset(cmds[i]->args, shell);
	else if (!ft_strcmp(builtins, "pwd"))
		ft_pwd(shell);
	if (shell->fdin > 2)
		close(shell->fdin);
	if (shell->fdout > 2)
		close(shell->fdout);
}

/* Esta funcion comprueba si el comando es un builtin o no. */

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") || !ft_strcmp(cmd, "cd") || !ft_strcmp(cmd,
			"env") || !ft_strcmp(cmd, "exit") || !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset") || !ft_strcmp(cmd, "pwd"))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:48:53 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 19:50:37 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion imprime las variables de entorno. */

int	ft_env_check_equal(char *cmd, t_shell *shell)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '=')
			break ;
		i++;
	}
	if (cmd[i] != '=')
	{
		ft_putstr_fd("env: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		shell->g_status = 127;
		error = 1;
	}
	return (error);
}

int	ft_env_check(char **full_cmd, t_shell *shell)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (full_cmd && full_cmd[i] != NULL && error == 0)
	{
		if (error == 0)
			error = ft_env_check_equal(full_cmd[i], shell);
		i++;
	}
	return (error);
}

void	ft_env(t_shell *shell, char **full_cmd)
{
	int	i;
	int	error;

	i = 0;
	error = ft_env_check(full_cmd, shell);
	if (error == 0)
	{
		while (shell->env[i])
		{
			ft_putstr_fd(shell->env[i], shell->fdout);
			ft_putstr_fd("\n", shell->fdout);
			i++;
		}
		i = 0;
		while (full_cmd && full_cmd[i])
		{
			ft_putstr_fd(full_cmd[i], shell->fdout);
			ft_putstr_fd("\n", shell->fdout);
			i++;
		}
	}
}

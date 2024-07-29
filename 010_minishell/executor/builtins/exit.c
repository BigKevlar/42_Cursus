/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:53:27 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:10:41 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion sale del minishell. */

void	ft_exit(char **cmd, t_shell *shell)
{
	shell->exit = 1;
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (cmd[0] && cmd[1])
	{
		shell->g_status = 1;
		ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
	}
	else if (cmd[0] && !ft_isdigit_str(cmd[0]))
	{
		shell->g_status = 1;
		ft_putstr_fd("exit: ", STDERR_FILENO);
		ft_putstr_fd(cmd[0], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	}
	else if (cmd[0])
		shell->g_status = ft_atoi(cmd[0]);
	else
		shell->g_status = 0;
}

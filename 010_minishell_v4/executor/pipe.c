/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:58:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 02:47:15 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_pipe_error(t_shell *shell)
{
	ft_putstr_fd("zsh: pipe or fork failed\n", 2);
	shell->exec_signal = 1;
	shell->g_status = 1;
}


void	apply_pipe(t_shell *shell)
{
	int		fd[2];

	if (pipe(fd) == -1)
		return (handle_pipe_error(shell));
	shell->fdnextin = fd[0];
	shell->fdout = fd[1];
}

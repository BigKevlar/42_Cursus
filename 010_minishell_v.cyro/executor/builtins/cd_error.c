/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:17:20 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 21:20:27 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_cd_error(char *path, t_shell *shell)
{
	ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	shell->g_status = 1;
}

void	handle_getcwd_error(t_shell *shell)
{
	ft_putstr_fd("pwd: error retrieving current directory: ", STDERR_FILENO);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	shell->g_status = 1;
}

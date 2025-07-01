/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:59:23 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 14:32:58 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta función crea o modifica una variable de entorno. */

int	update_env_var(char *name_var, char *value_var, t_shell *shell)
{
	int	x;
	int	updated;

	x = 0;
	updated = 0;
	while (shell->env[x])
	{
		if (!ft_strncmp(shell->env[x], name_var, ft_strlen(name_var))
			&& shell->env[x][ft_strlen(name_var)] == '=')
		{
			free(shell->env[x]);
			shell->env[x] = ft_strjoin(name_var, "=");
			if (value_var)
			{
				free(shell->env[x]);
				shell->env[x] = ft_strjoin(shell->env[x], value_var);
			}
			updated = 1;
		}
		x++;
	}
	return (updated);
}

void	ft_export2(char *full_cmd, t_shell *shell)
{
	char	*name_var;
	char	*value_var;
	char	*equal_sign;

	equal_sign = ft_strchr(full_cmd, '=');
	if (equal_sign)
	{
		*equal_sign = '\0';
		name_var = full_cmd;
		value_var = equal_sign + 1;
		if (!update_env_var(name_var, value_var, shell))
			ft_new_env(name_var, value_var, shell);
	}
}

void	print_all_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		ft_putstr_fd("declare -x ", shell->fdout);
		ft_putstr_fd(shell->env[i], shell->fdout);
		ft_putstr_fd("\n", shell->fdout);
		i++;
	}
}

void	ft_export(char **full_cmd, t_shell *shell)
{
	int	i;
	int	bad_env;

	i = 0;
	if (!full_cmd[0])
		print_all_env(shell);
	else
	{
		i = 0;
		while (full_cmd[i] != NULL)
		{
			bad_env = is_bad_env(full_cmd[i]);
			if (bad_env <= 0)
			{
				ft_env_error(bad_env, full_cmd[i]);
				shell->g_status = 1;
			}
			else
				ft_export2(full_cmd[i], shell);
			i++;
		}
	}
}

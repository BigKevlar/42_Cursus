/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:59:23 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/21 18:18:25 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta función crea o modifica una variable de entorno. */

void	ft_env_error(int bad_env, char *env)
{
	int	i;

	i = 0;
	if (bad_env == 0)
	{
		ft_putstr_fd("export: not an identifier: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
		{
			ft_putchar_fd(env[i], STDERR_FILENO);
			i++;
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (bad_env == -3)
	{
		if (env[1] != '\0')
			bad_env = -2;
		else
			ft_putstr_fd("zsh: bad assignment\n", STDERR_FILENO);
	}
	else if (bad_env == -1)
	{
		ft_putstr_fd("export: not valid in this context: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
		{
			ft_putchar_fd(env[i], STDERR_FILENO);
			i++;
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else
	if (bad_env == -2)
	{
		ft_putstr_fd("zsh: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
			i++;
		i++;
		ft_putchar_fd(env[i], STDERR_FILENO);
		ft_putstr_fd(" not found\n", STDERR_FILENO);
	}
}

int	is_bad_env(char *env)
{
	int	i;

	i = 0;
	if (ft_isdigit(env[i]))
		return (0);
	if (env[i] == '=')
		return (-3);
	while (env[i])
	{
		if (env[i] == '=')
		{
			if (env[i + 1] == '=' && env[i + 2] != '\0')
				return (-2);
		}
		i++;
	}
	i = 0;
	while (env[i] && env[i] != '=')
	{
		if (!ft_isalnum(env[i]) && env[i] != '_')
			return (-1);
		i++;
	}
	return (1);
}

void	ft_new_env(char *name_var, char *value_var, t_shell *shell)
{
	int		i;
	char	**new_env;
	char	*new_entry;

	i = 0;
	while (shell->env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return ;
	i = 0;
	while (shell->env[i])
	{
		new_env[i] = ft_strdup(shell->env[i]);
		i++;
	}
	new_entry = ft_strjoin(name_var, "=");
	if (value_var)
	{
		char *temp = ft_strjoin(new_entry, value_var);
		free(new_entry);
		new_entry = temp;
	}
	new_env[i] = new_entry;
	new_env[i + 1] = NULL;
	shell->env = new_env;
}

void	ft_export(char **full_cmd, t_shell *shell)
{
	int		i;
	int		bad_env;
	char	*name_var;
	char	*value_var;
	char	*equal_sign;
	int		x;

	i = 0;
	int j = 0;
	if (!full_cmd[1])
	{
		while (shell->env[i])
		{
			ft_putendl_fd(shell->env[i], STDOUT_FILENO);
			i++;
		}
		return ;
	}
	else
	{
		i = 1;
		while (full_cmd[i] != NULL)
		{
			bad_env = is_bad_env(full_cmd[i]);
			if(bad_env <= 0)
			{
				ft_env_error(bad_env, full_cmd[i]);
				shell->g_status = 1;
			}
			else
			{
				equal_sign = ft_strchr(full_cmd[i], '=');
				if (equal_sign)
				{
					*equal_sign = '\0';
					name_var = full_cmd[i];
					value_var = equal_sign + 1;
				}
				x = 0;
				if (equal_sign)
				{
					while (shell->env[x])
					{
						if (!ft_strncmp(shell->env[x], name_var, ft_strlen(name_var))
							&& shell->env[x][ft_strlen(name_var)] == '=')
						{
							free(shell->env[x]);
							shell->env[x] = ft_strjoin(name_var, "=");
							if (value_var)
								shell->env[x] = ft_strjoin(shell->env[x], value_var);
							j = 1;
						}
						x++;
					}
					if (j == 0)
						ft_new_env(name_var, value_var, shell);
				}
			}
			j = 0;
			i++;
		}
	}
}

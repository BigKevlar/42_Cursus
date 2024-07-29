/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:41:00 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 14:39:42 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env_error2(int bad_env, char *env, int i)
{
	if (bad_env == -1)
	{
		ft_putstr_fd("export: not valid in this context: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
		{
			ft_putchar_fd(env[i], STDERR_FILENO);
			i++;
		}
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	else if (bad_env == -2)
	{
		ft_putstr_fd("export: ", STDERR_FILENO);
		while (env[i] && env[i] != '=')
			i++;
		i++;
		ft_putchar_fd(env[i], STDERR_FILENO);
		ft_putstr_fd(": not a valid identifier\n", STDERR_FILENO);
	}
}

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
		{
			ft_putstr_fd("export: not valid in this context", STDERR_FILENO);
			ft_putchar_fd('\n', STDERR_FILENO);
		}
	}
	ft_env_error2(bad_env, env, i);
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

char	*create_new_entry(char *value_var, char *name_var)
{
	char	*new_entry;
	char	*temp;

	new_entry = ft_strjoin(name_var, "=");
	if (value_var)
	{
		temp = ft_strjoin(new_entry, value_var);
		free(new_entry);
		new_entry = temp;
		free(temp);
	}
	return (new_entry);
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
	new_entry = create_new_entry(value_var, name_var);
	new_env[i] = new_entry;
	new_env[i + 1] = NULL;
	ft_strd_free(shell->env);
	shell->env = new_env;
	free(new_entry);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:59:23 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/02 16:14:50 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion crea o modifica una variable de entorno. */

void	ft_new_env(char *name_var, char *value_var, t_shell *shell)
{
	int		i;
	char	**new_env;

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
	new_env[i] = ft_strjoin(name_var, value_var);
	new_env[i + 1] = NULL;
	free(shell->env);
	shell->env = new_env;
}

void	ft_export(char *name_var, char *value_var, t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], name_var, ft_strlen(name_var))
			&& shell->env[i][ft_strlen(name_var)] == '=')
		{
			free(shell->env[i]);
			shell->env[i] = ft_strjoin(name_var, value_var);
		}
		i++;
	}
	ft_new_env(name_var, value_var, shell);
}

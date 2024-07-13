/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:39:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/02 16:16:34 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion elimina una variable de entorno. */

void	ft_search_env(char *name_var, t_shell *shell)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(name_var);
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], name_var, len)
			&& shell->env[i][len] == '=')
		{
			free(shell->env[i]);
			j = i;
			while (shell->env[j])
			{
				shell->env[j] = shell->env[j + 1];
				j++;
			}
			return ;
		}
		i++;
	}
}

int	ft_unset(char *name_var, t_shell *shell)
{
	int		i;
	char	**new_env;

	i = 0;
	ft_search_env(name_var, shell);
	new_env = ft_calloc(i, sizeof(char *));
	while (shell->env[i])
	{
		new_env[i] = ft_strdup(shell->env[i]);
		i++;
	}
	free(shell->env);
	shell->env = new_env;
	return (EXIT_SUCCESS);
}

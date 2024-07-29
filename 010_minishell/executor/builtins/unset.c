/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:39:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:31:57 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset_env(char **name_var, t_shell *shell, int x)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (shell->env[i] != NULL)
	{
		len = ft_strlen(name_var[x]);
		if (!ft_strncmp(shell->env[i], name_var[x], len)
			&& shell->env[i][len] == '=')
		{
			free(shell->env[i]);
			j = i;
			while (shell->env[j] != NULL)
			{
				shell->env[j] = shell->env[j + 1];
				j++;
			}
			shell->env[j] = NULL;
			i--;
		}
		i++;
	}
}

void	ft_unset(char **name_var, t_shell *shell)
{
	int	x;

	x = 0;
	while (name_var[x] != NULL)
	{
		ft_unset_env(name_var, shell, x);
		x++;
	}
}

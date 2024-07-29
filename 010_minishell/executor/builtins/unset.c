/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:39:41 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 11:26:28 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_unset_error(char *name_var, t_shell *shell)
{
	ft_putstr_fd("unset: '", STDERR_FILENO);
	ft_putstr_fd(name_var, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	shell->g_status = 1;
}

int	ft_unset_check(char **name_var, t_shell *shell)
{
	int	x;
	int	i;

	x = 1;
	i = 0;
	while (name_var[x] != NULL)
	{
		i = 0;
		if (ft_isdigit(name_var[x][0]))
		{
			ft_unset_error(name_var[x], shell);
			return (1);
		}
		while (name_var[x][i] != '\0')
		{
			if (!ft_isalnum(name_var[x][i]) && name_var[x][i] != '_')
			{
				ft_unset_error(name_var[x], shell);
				return (1);
			}
			i++;
		}
		x++;
	}
	return (0);
}

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
	int		x;

	x = 1;
	if (!(name_var[1]))
	{
		ft_putstr_fd("unset: not enough arguments\n", STDERR_FILENO);
		shell->g_status = 1;
		return ;
	}
	if (ft_unset_check(name_var, shell))
		return ;
	while (name_var[x] != NULL)
	{
		ft_unset_env(name_var, shell, x);
		x++;
	}
}

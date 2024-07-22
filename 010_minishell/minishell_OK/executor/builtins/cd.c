/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:05:28 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 11:06:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion cambia el directorio actual de trabajo. */

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] == name[j] && name[j] != '\0')
			j++;
		if (env[i][j] == '=' && name[j] == '\0')
		{
			value = ft_strdup(env[i] + j + 1);
			if (value == NULL)
				return (NULL);
			return (value);
		}
		i++;
	}
	return (NULL);
}

void	ft_cd_oldpwd(t_shell *shell)
{
	char	*oldpwd;

	oldpwd = ft_getenv("OLDPWD", shell->env);
	if (oldpwd == NULL)
	{
		ft_putstr_fd("cd: OLDPWD not set\n", STDERR_FILENO);
		shell->g_status = 1;
		return ;
	}
	if (chdir(oldpwd) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(oldpwd, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		shell->g_status = 1;
	}
	ft_putstr_fd(oldpwd, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	ft_cd_home(t_shell *shell)
{
	char	*home;

	home = ft_getenv("HOME", shell->env);
	if (home == NULL)
		return ;
	if (chdir(home) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(home, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		shell->g_status = 1;
	}
}

void	ft_cd(char **full_cmd, t_shell *shell)
{
	if (full_cmd[2] != NULL)
	{
		write(STDERR_FILENO, "cd: too many arguments\n", 23);
		shell->g_status = 1;
		return ;
	}
	if (full_cmd[1] == NULL)
		ft_cd_home(shell);
	else if (full_cmd[1][0] == '~')
		ft_cd_home(shell);
	else if (full_cmd[1][0] == '-')
		ft_cd_oldpwd(shell);
	else if (chdir(full_cmd[1]) == -1)
	{
		ft_putstr_fd("cd: no such file or directory: ", STDERR_FILENO);
		ft_putstr_fd(full_cmd[1], STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
		shell->g_status = 1;
	}
}

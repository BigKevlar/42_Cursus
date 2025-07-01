/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:05:28 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:13:05 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion cambia el directorio actual a uno nuevo. */

void	update_pwd(t_shell *shell)
{
	char	cwd[PATH_MAX];
	int		i;

	i = 0;
	if (getcwd(cwd, PATH_MAX) == NULL)
	{
		handle_getcwd_error(shell);
		return ;
	}
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], "PWD=", 4) == 0)
		{
			free(shell->env[i]);
			shell->env[i] = ft_strjoin("PWD=", cwd);
			if (shell->env[i] == NULL)
			{
				shell->g_status = 1;
				return ;
			}
			break ;
		}
		i++;
	}
}

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
	ft_putstr_fd(oldpwd, shell->fdout);
	ft_putchar_fd('\n', shell->fdout);
	free(oldpwd);
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
	free(home);
}

void	ft_cd(char **full_cmd, t_shell *shell)
{
	if (full_cmd[1] != NULL)
	{
		write(STDERR_FILENO, "cd: too many arguments\n", 23);
		shell->g_status = 1;
		return ;
	}
	shell->oldpwd = ft_getenv("PWD", shell->env);
	if (full_cmd[0] == NULL)
		ft_cd_home(shell);
	else if (full_cmd[0][0] == '~')
		ft_cd_home(shell);
	else if (full_cmd[0][0] == '-')
		ft_cd_oldpwd(shell);
	else if (chdir(full_cmd[0]) == -1)
		handle_cd_error(full_cmd[0], shell);
	if (shell->g_status == 1)
	{
		free(shell->oldpwd);
		shell->oldpwd = NULL;
	}
	else
		update_pwd(shell);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:26:40 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:58:18 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	update_shlvl(t_shell *shell)
{
	char	*shlvl;
	int		i;
	int		lvl;

	i = 0;
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(shell->env[i], "SHLVL=", 6) == 0)
		{
			shlvl = ft_strdup(shell->env[i] + 6);
			lvl = ft_atoi(shlvl);
			free(shlvl);
			lvl++;
			shlvl = ft_itoa(lvl);
			free(shell->env[i]);
			shell->env[i] = ft_strjoin("SHLVL=", shlvl);
			free(shlvl);
			return ;
		}
		i++;
	}
}

void	update_oldpwd(t_shell *shell, int i)
{
	if (shell->oldpwd != NULL && ft_strncmp(shell->env[i], "OLDPWD=", 7) == 0)
	{
		free(shell->env[i]);
		shell->env[i] = ft_strjoin("OLDPWD=", shell->oldpwd);
	}
	free(shell->oldpwd);
}

void	reset_env(t_shell *shell, t_cmd **cmds)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (shell->env[i])
	{
		update_oldpwd(shell, i);
		if (ft_strncmp(shell->env[i], "_=", 2) == 0)
		{
			if (cmds[0]->args && cmds[0]->args[0] != NULL)
			{
				while (cmds[0]->args[x] != NULL)
					x++;
				free(shell->env[i]);
				shell->env[i] = ft_strjoin("_=", cmds[0]->args[x - 1]);
			}
			else if (cmds[0]->cmd != NULL)
			{
				free(shell->env[i]);
				shell->env[i] = ft_strjoin("_=", cmds[0]->cmd);
			}
		}
		i++;
	}
}

char	**ft_undo(t_cmd **cmds, int i)
{
	char	**exc;
	int		x;

	x = 0;
	while (cmds[i]->args != NULL && cmds[i]->args[x] != NULL)
		x++;
	exc = calloc(x + 1, sizeof(char *));
	x = 0;
	exc[x] = ft_strdup(cmds[i]->cmd);
	x++;
	if (cmds[i]->args != NULL)
	{
		while (cmds[i]->args[x - 1] != NULL && cmds[i]->args != NULL)
		{
			exc[x] = ft_strdup(cmds[i]->args[x - 1]);
			x++;
		}
	}
	exc[x] = NULL;
	return (exc);
}

int	error_msg(char *path)
{
	DIR	*dir;
	int	status;

	status = 0;
	dir = opendir(path);
	ft_putstr_fd(path, STDERR_FILENO);
	if (ft_strchr(path, '/') == NULL)
		ft_putstr_fd(": command not found", STDERR_FILENO);
	else if (access(path, F_OK) == -1)
		ft_putstr_fd(": No such file or directory", 2);
	else if (dir != NULL)
	{
		ft_putstr_fd(": is a directory", 2);
		closedir(dir);
	}
	else if (access(path, X_OK) == -1)
		ft_putstr_fd(": Permission denied", 2);
	if (ft_strchr(path, '/') == NULL || (dir == NULL))
		status = 127;
	else
		status = 126;
	if (dir != NULL)
		closedir(dir);
	ft_putchar_fd('\n', 2);
	return (status);
}

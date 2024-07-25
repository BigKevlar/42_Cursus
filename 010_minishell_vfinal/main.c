/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/25 15:23:01 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

/*
	Borramos los espacios que puede haber al final del prompt.
*/

void	delete_end_spaces(char *str)
{
	int	len;

	if (str == NULL)
		return ;
	len = strlen(str);
	while (len > 0 && str[len - 1] == ' ')
	{
		len--;
	}
	str[len] = '\0';
}

static int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	init_struct(t_shell *shell, char **envp)
{
	int	i;

	i = 0;
	shell->cmds = NULL;
	shell->prompt = NULL;
	shell->parsed_prompt = NULL;
	while (envp[i] != NULL)
		i++;
	shell->env = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (envp[i] != NULL)
	{
		shell->env[i] = ft_strdup(envp[i]);
		i++;
	}
	shell->full_cmd = NULL;
	shell->cmd_path = NULL;
	shell->g_status = 0;
	setup_redirections(shell);
	reset_fds(shell);
	shell->exit = 0;
	shell->exec_signal = 0;
	shell->oldpwd = NULL;
	update_shlvl(shell);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;

	if (argc != 1 || argv[1] != NULL)
		return (ft_putstr_fd(RED "minishell: invalid arguments\n" NC,
				STDERR_FILENO), EXIT_FAILURE);
	init_struct(&shell, envp);
	while (shell.exit == 0)
	{
		if_signal();
		line = readline("Minishell$~ ");
		if (line == NULL)
			break ;
		else if (ft_check_line(line) == 0)
		{
			add_history(line);
			init_prompt(&shell, line);
			if (shell.parse_error == 0)
				execute(shell.cmds, &shell);
		}
		if (line)
			free(line);
	}
	ft_free_struct(&shell);
	return (ft_strd_free(shell.env), 0);
}

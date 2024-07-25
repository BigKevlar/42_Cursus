/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 13:30:19 by jmartos-         ###   ########.fr       */
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

int	insert_tab(int count, int key)
{
	if (rl_line_buffer[0] == '\0' || strspn(rl_line_buffer,
			" \t") == strlen(rl_line_buffer))
	{
		rl_insert_text("\t");
		rl_redisplay();
		return (0);
	}
	else
		return (rl_complete(count, key));
}

void	init_struct(t_shell *shell, char **envp)
{
	shell->prompt = NULL;
	shell->parsed_prompt = NULL;
	shell->env = envp;
	shell->full_cmd = NULL;
	shell->cmd_path = NULL;
	shell->g_status = 0;
	setup_redirections(shell);
	reset_fds(shell);
	shell->exit = 0;
	shell->exec_signal = 0;
	rl_bind_key('\t', insert_tab);
	shell->oldpwd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_shell	shell;
	t_cmd	cmd;

	if (argc != 1 || argv[1] != NULL)
	{
		ft_putstr_fd(RED "minishell: invalid arguments\n" NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	init_struct(&shell, envp);
	while (shell.exit == 0)
	{
		if_signal();
		line = readline("Minishell$~ ");
		if (line == NULL)
			break ;
		else if (ft_check_line(line) == 0)
		{
			shell.prompt = line;
			add_history(line);
			init_prompt(&shell, &cmd);
			execute(&cmd, &shell);
		}
		free(line);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/13 18:41:43 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	0 = close
	1 = open
*/
int	g_signal_mutex;

// CTRL + 'C': nueva linea con nueva entrada.
// CTRL + '\': termina el shell.
void	if_signal(void)
{
	signal(SIGQUIT, SIG_IGN); // CTRL + '\'
	if (SIGINT) // CTRL + 'C'
	{
		g_signal_mutex = 1;
		signal(SIGINT, handle_SIGINT);
	}
	g_signal_mutex = 0;
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
	g_signal_mutex = 0;
	cmd.cmd_exit_status = 0;
	while (1)
	{
		if_signal();
		line = readline("Minishell$~ ");
		if (line == NULL)
			handle_EOF(line);
		else if(ft_check_line(line) == 0)
		{
			shell.prompt = line;
			add_history(line);
			shell.env = envp;
			init_prompt(&shell, &cmd, envp);
			exec_choose(&shell, &cmd);
            // cmd.cmd_exit_status = NI IDEA DE COMO OBTENER EL ESTADOD DE SALIDA DEL ULTIMO COMANDO.
		}
		free(line);
	}
	return (0);
}

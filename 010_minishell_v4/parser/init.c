/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/24 13:28:12 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Inicializa la estructura para controlar los pipes y redicrecciones.
*/
void	init_pipe_red(t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}

/*
	Iniciamos la estructura con la copia de keys y values de las
	variables de entorno, para usarlas en el parseo.
*/
t_var	**init_envp(char **envp)
{
	t_var	**list_var;
	int		c;
	int		i;

	i = 0;
	c = ft_strd_len(envp);
	list_var = ft_calloc(sizeof(t_var *), c + 1);
	if (!list_var)
		return (NULL);
	while (i < c)
	{
		list_var[i] = ft_calloc(sizeof(t_var), 1);
		list_var[i]->key = ft_strndup(envp[i],
				ft_strchr(envp[i], '=') - envp[i]);
		list_var[i]->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		i++;
	}
	list_var[i] = NULL;
	return (list_var);
}

/*
	Iniciamos el prompt:

		- Parseamos los arguementos.
		- super_split.
		- Expansion de las variables de entorno.
*/
void	init_prompt(t_shell *shell, t_cmd *cmd)
{
	int	i;

	i = 0;
	delete_end_spaces(shell->prompt);
	if (!check_cmd(shell))
	{
		ft_printf("zsh: parse error\n");
		shell->g_status = 2;
		shell->prompt = NULL;
	}
	shell->full_cmd = parse_input(shell->prompt);
	shell->split_cmd = ft_matrixdup(shell->full_cmd);
	executor_split(shell, cmd);
	expand_env_var(shell, shell->env);
	while (shell->full_cmd[i] != NULL)
	{
		remove_quotes(shell->full_cmd[i]);
		i++;
	}
}

/*
	Segunda parte de init_prompt.
*/
char	**parse_input(char *prompt)
{
	char	**cmd;

	cmd = super_split(prompt);
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_strd_lastdel(cmd);
	return (cmd);
}

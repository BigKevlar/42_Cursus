/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/25 15:12:26 by rguerrer         ###   ########.fr       */
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
		list_var[i]->key = ft_strndup(envp[i], ft_strchr(envp[i], '=')
				- envp[i]);
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
void	init_prompt(t_shell *shell, char *line)
{
	shell->prompt = line;
	shell->parse_error = 0;
	delete_end_spaces(shell->prompt);
	if (!check_cmd(shell))
	{
		ft_printf("minishell: parse error\n");
		shell->parse_error = 1;
		shell->prompt = NULL;
		return ;
	}
	parse_input(shell);
	shell->split_cmd = ft_matrixdup(shell->full_cmd);
	executor_split(shell);
	ft_strd_free(shell->full_cmd);
	ft_strd_free(shell->split_cmd);
}

/*
	Segunda parte de init_prompt.
*/
void	parse_input(t_shell *shell)
{
	shell->full_cmd = super_split(shell->prompt);
	if (shell->prompt[ft_strlen(shell->prompt) - 1] == ' ')
		shell->full_cmd = ft_strd_lastdel(shell->full_cmd);
	expand_env_var(shell, shell->env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/25 16:13:19 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	replace_var_env(char **cmd, int *j, char *status, t_var **list_var)
{
	char	*key;
	char	*var;
	char	*tmp;

	if ((*cmd)[*j + 1] == '?')
	{
		tmp = *cmd;
		*cmd = ft_delete_str(tmp, *j, *j + 1);
		free(tmp);
		tmp = *cmd;
		*cmd = ft_insert_str(tmp, status, *j);
		free(tmp);
		(*j)++;
	}
	else
	{
		key = find_varname(*cmd, *j + 1);
		*cmd = ft_delete_str(*cmd, *j, *j + ft_strlen(key));
		var = get_var(list_var, key);
		tmp = *cmd;
		*cmd = ft_insert_str(tmp, var, *j);
		free(key);
		free(var);
		free(tmp);
	}
}

static void	do_command(char **cmd, t_var **list_var, char *status)
{
	int	j;
	int	is_at_dollar;
	int	is_alpha;
	int	is_underscore;
	int	is_question_mark;

	j = 0;
	while ((*cmd)[j])
	{
		is_at_dollar = (*cmd)[j] == '$';
		is_alpha = ft_isalpha((*cmd)[j + 1]);
		is_underscore = (*cmd)[j + 1] == '_';
		is_question_mark = (*cmd)[j + 1] == '?';
		if (is_at_dollar && (is_alpha || is_underscore || is_question_mark))
			replace_var_env(cmd, &j, status, list_var);
		j++;
	}
}

void	restore_dolar(char **dolar)
{
	int	i;
	int	j;

	i = 0;
	while (dolar[i])
	{
		j = 0;
		while (dolar[i][j])
		{
			if (dolar[i][j] == 1)
				dolar[i][j] = '$';
			j++;
		}
		i++;
	}
}

void	expand_env_var(t_shell *shell, char **envp)
{
	t_var	**list_var;
	int		i;
	char	*status;

	list_var = init_envp(envp);
	status = ft_itoa(shell->g_status);
	i = 0;
	while (shell->full_cmd[i])
	{
		if (shell->full_cmd[i][0] != '\'')
			do_command(&shell->full_cmd[i], list_var, status);
		i++;
	}
	restore_dolar(shell->full_cmd);
	free(status);
	i = 0;
	while (shell->full_cmd[i] != NULL)
	{
		remove_quotes(shell->full_cmd[i]);
		i++;
	}
	ft_free_envs(list_var);
}

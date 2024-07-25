/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/24 18:06:36 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Sobreescribimos el key por la variable de entonrno despues de un $.
*/
/*
static char	*handle_dollar(char *dollar, t_var **list_var, t_shell *shell)
{
	char	*res;
	char	*key;
	char	*value;
	char	*end;

	if (*(dollar + 1) == '?')
	{
		res = ft_itoa(shell->g_status);
	}
	else
	{
		end = dollar + 1;
		while (*end && (ft_isalnum(*end) || *end == '_'))
			end++;
		key = ft_strndup(dollar + 1, end - dollar - 1);
		value = get_var(list_var, key);
		res = ft_strdup(value);
		free(key);
	}
	return (res);
}

char	*key_x_value(t_var **list_var, char *str, t_shell *shell)
{
	char	*res;
	char	*dollar;
	char	*dollar_res;
	char	*temp;

	res = ft_strdup("");
	dollar = ft_strchr(str, '$');
	while (dollar != NULL)
	{
		temp = ft_strndup(str, dollar - str);
		res = ft_strjoin(res, temp);
		free(temp);
		dollar_res = handle_dollar(dollar, list_var, shell);
		res = ft_strjoin(res, dollar_res);
		free(dollar_res);
		if (*(dollar + 1) == '?')
			str = dollar + 2;
		else
			str = dollar + 1;
		dollar = ft_strchr(str, '$');
	}
	temp = ft_strdup(str);
	res = ft_strjoin(res, temp);
	free(temp);
	return (res);
}
*/
/*
	Expande las variables de entorno.
*/
static void	replace_dollar(char **cmd, int *j, char *status, t_var **list_var)
{
	char	*key;

	if ((*cmd)[*j + 1] == '?')
	{
		*cmd = ft_delete_str(*cmd, *j, *j + 1);
		*cmd = ft_insert_str(*cmd, status, *j);
		(*j)++;
	}
	else
	{
		key = find_varname(*cmd, *j + 1);
		*cmd = ft_delete_str(*cmd, *j, *j + ft_strlen(key));
		*cmd = ft_insert_str(*cmd, get_var(list_var, key), *j);
		free(key);
	}
}

static void	do_command(char **cmd, t_var **list_var, char *status)
{
	int	j;

	j = 0;
	while ((*cmd)[j])
	{
		if ((*cmd)[j] == '$' && ((!ft_isalnum((*cmd)[j + 1])) && ((*cmd)[j + 1] != '_')))
			(*cmd)[j] = '$';
		else if ((*cmd)[j] == '$')
			replace_dollar(cmd, &j, status, list_var);
		j++;
	}
	//if (strchr(*cmd, '\"'))
	//	*cmd = key_x_value(list_var, *cmd, NULL);
}

void restore_dolar(char **dolar)
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
}

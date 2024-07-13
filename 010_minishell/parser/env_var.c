/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/13 18:51:22 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_var **parse_envp(char **envp)
{
	t_var **list_var;
	int c;
	int i;

	i = 0;
	c = ft_strd_len(envp);
	list_var = ft_calloc(sizeof(t_var *), c + 1); // +1 para NULL.
	if (!list_var)
        return (NULL); // error por falta de memoria.
	while (i < c)
	{
		list_var[i] = ft_calloc(sizeof(t_var), 1);
		if (!list_var[i])
        {
            while (i-- > 0)
            {
                free(list_var[i]->key);
                free(list_var[i]->value);
                free(list_var[i]);
				
            }
            free(list_var);
            return (NULL); // error por falta de memoria.
		}
		list_var[i]->key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		list_var[i]->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		i++;
	}
	list_var[i] = NULL;
	return (list_var);
}

char *get_var(t_var **list_var, char *key)
{
	int i;

	i = 0;
	while (list_var[i])
	{
		if (ft_strcmp(list_var[i]->key, key) == 0)
			return (ft_strdup(list_var[i]->value));
		i++;
	}
	return (ft_strdup(""));
}

char *find_varname(char *str)
{
	int start = 0;
	int started_var = 0;
	int i = 0;

	while (str[i])
	{
		if (str[i] == '$' && (ft_isalpha(str[i + 1]) || str[i + 1] == '_'))
		{
			start = i + 1;
			started_var = 1;
		}
		if (i > start && started_var && !(ft_isalnum(str[i + 1]) || str[i + 1] == '_'))
		{
			return ft_strndup(str + start - 1, (i - start) + 2);
		}
		i++;
	}
	return NULL;
}

char *replace_value_var(t_cmd *cmd, t_var **env_list, char *str)
{
	char *varname;
	char *start;
	char *end;
	char *tmp2;
	char *tmp;

	varname = find_varname(str); // $VAR
	while (varname)
	{
		if (ft_strcmp(varname, "$?") == 0)
			tmp = implement_dolar_question(str, start, end, cmd->cmd_exit_status);
		else
		{
			start = ft_strnstr(str, varname, ft_strlen(str)); // find where the var starts: "hello $USER test" -> "$USER test"
			if (start)
				end = start + ft_strlen(varname); // find where the var ends: "$USER test" -> "USER test"
			else
				return (NULL);										// Panic, we should never reach this point
			tmp = ft_strndup(str, start - str);						// left side of the var: "hello $USER test" -> "hello "
			tmp2 = ft_strjoin(tmp, get_var(env_list, varname + 1)); // "hello " + "user" -> "hello user"
			free(tmp);
			tmp = ft_strjoin(tmp2, end); // "hello user" + " test" -> "hello user test"
			free(tmp2);
			free(str);
			str = tmp;					 // "hello user test"
		}
		varname = find_varname(str); // find next var
	}
	remove_dquotes(str);
	return (str);
}

void expand_env_var(t_cmd *cmd, char **envp)
{
	t_var **list_var;
	int i;
	char *key;

	i = 0;
	list_var = parse_envp(envp); // VARIABLES DE ENTORNO
	while (cmd->full_cmd[i])
	{
		if (cmd->full_cmd[i][0] == '$')
		{
			key = cmd->full_cmd[i];
			cmd->full_cmd[i] = get_var(list_var, key + 1); // SOBREESCRIBIENDO!
			free(key);
		}
		else if (cmd->full_cmd[i][0] == '"')
			cmd->full_cmd[i] = replace_value_var(cmd, list_var, cmd->full_cmd[i]); // SOBREESCRIBIENDO!
		i++;
	}
}

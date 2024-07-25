/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:25:24 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/24 15:40:50 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		pipe_counter(char **str)
{
	int	i;
	int cont;

	i = 0;
	cont = 1;
	while (str[i])
	{
		if (str[i][0] == '|')
			cont++;
		i++;
	}
	return (cont);
}

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

void executor_split(t_shell *shell, t_cmd *cmd)
{
    int num_cmds = pipe_counter(shell->split_cmd);
    int pos = 0;
    int i_com = 0;
    int i_red = 0;
    int i_arg = 0;

    cmd = (t_cmd *)ft_calloc(num_cmds, sizeof(t_cmd));

    while (shell->split_cmd[pos])
	{
        if (strcmp(shell->split_cmd[pos], "|") == 0) {
            i_com++;
            i_red = 0;
            i_arg = 0;
            pos++;
            continue;
        }

        if (shell->split_cmd[pos][0] == '<') {
            if (cmd[i_com].incmd == NULL) {
                cmd[i_com].incmd = (char **)ft_calloc(2, sizeof(char *));
            } else {
                char **new_in_reds = (char **)ft_calloc(i_red + 2, sizeof(char *));
                memcpy(new_in_reds, cmd[i_com].incmd, i_red * sizeof(char *));
                free(cmd[i_com].incmd);
                cmd[i_com].incmd = new_in_reds;
            }
            cmd[i_com].incmd[i_red++] = strdup(shell->split_cmd[pos]);
            cmd[i_com].incmd[i_red] = NULL;
        } else if (shell->split_cmd[pos][0] == '>') {
            if (cmd[i_com].outcmd == NULL) {
                cmd[i_com].outcmd = (char **)ft_calloc(2, sizeof(char *));
            } else {
                char **new_out_reds = (char **)ft_calloc(i_red + 2, sizeof(char *));
                memcpy(new_out_reds, cmd[i_com].outcmd, i_red * sizeof(char *));
                free(cmd[i_com].outcmd);
                cmd[i_com].outcmd = new_out_reds;
            }
            cmd[i_com].outcmd[i_red++] = strdup(shell->split_cmd[pos]);
            cmd[i_com].outcmd[i_red] = NULL;
        } else {
            if (cmd[i_com].cmd == NULL) {
                cmd[i_com].cmd = strdup(shell->split_cmd[pos]);
            } else {
                if (cmd[i_com].args == NULL) {
                    cmd[i_com].args = (char **)ft_calloc(2, sizeof(char *));
                } else {
                    char **new_args = (char **)ft_calloc(i_arg + 2, sizeof(char *));
                    memcpy(new_args, cmd[i_com].args, i_arg * sizeof(char *));
                    free(cmd[i_com].args);
                    cmd[i_com].args = new_args;
                }
                cmd[i_com].args[i_arg++] = strdup(shell->split_cmd[pos]);
                cmd[i_com].args[i_arg] = NULL;
            }
        }
        pos++;
		// Verificar los comandos, redirecciones y argumentos almacenados
    	for (int i = 0; i < i_com; i++) {
    	    printf("Command %d: %s\n", i + 1, cmd[i].cmd);
	
    	    printf("Arguments: ");
    	    if (cmd[i].args) {
    	        int j = 0;
    	        while (cmd[i].args[j]) {
    	            printf("%s ", cmd[i].args[j]);
    	            j++;
    	        }
    	    }
    	    printf("\nInput Redirections: ");
    	    if (cmd[i].incmd) {
    	        int j = 0;
    	        while (cmd[i].incmd[j]) {
    	            printf("%s ", cmd[i].incmd[j]);
    	            j++;
    	        }
    	    }
    	    printf("\nOutput Redirections: ");
    	    if (cmd[i].outcmd) {
    	        int j = 0;
    	        while (cmd[i].outcmd[j]) {
    	            printf("%s ", cmd[i].outcmd[j]);
    	            j++;
    	        }
    	    }
    	    printf("\n\n");
    	}
    }
}

/*
while (shell->split_cmd[i])
	{
		j = 0;
		while (shell->split_cmd[i][j])
		{
			if (cmd->split[i][j] == '<')
			{
				cmd->incmd[i][j] = cmd->split[i][j];
				if (cmd->split[i][j + 1] == '<')
				{
					j++;
					cmd->incmd[i][j] = cmd->split[i][j];
				}
				j++;
				while (cmd->args[i][j] != ' ')
				{
					cmd->args[i][j] = cmd->split[i][j];
					j++;
				}
			}
			else if (cmd->split[i][j] == '>')
			{
				cmd->outcmd[i][j] = cmd->split[i][j];
				if (cmd->split[i][j + 1] == '>')
				{
					j++;
					cmd->incmd[i][j] = cmd->split[i][j];
				}
				j++;
				while (cmd->args[i][j] != ' ')
				{
					cmd->args[i][j] = cmd->split[i][j];
					j++;
				}
			}
			else
			{
				while (cmd->args[i][j] != ' ')
				{
					cmd->args[i][j] = cmd->split[i][j];
					j++;
				}
			}
		}
		i++;
	}
*/
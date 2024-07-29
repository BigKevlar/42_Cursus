/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:30:25 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/22 17:58:44 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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

// Sobreescribimos el key la variable de entonrno despues de un $ por el value.
char *replace_key_x_value(t_var **list_var, char *str, t_shell *shell)
{
    char *result = ft_strdup(""); // Resultado inicial = vacío.
    char *dollar;

    while ((dollar = ft_strchr(str, '$')))
    {
        // Copiamos la parte antes del $
        result = ft_insert_str(result, ft_strndup(str, dollar - str), ft_strlen(result));
        if (*(dollar + 1) == '?')
        {
            // Manejo de $?.
            result = ft_insert_str(result, ft_itoa(shell->g_status), ft_strlen(result));
            str = dollar + 2; // Avanzamos más allá de $?.
        }
        else
        {
            // Encontramos el final del nombre de la variable.
            char *end = dollar + 1;
            while (*end && (ft_isalnum(*end) || *end == '_'))
                end++;
            
            char *key = ft_strndup(dollar + 1, end - dollar - 1);
            char *value = get_var(list_var, key);
            result = ft_insert_str(result, value, ft_strlen(result));
            free(key);
            str = end;
        }
    }
    // Añadimos cualquier texto restante.
    result = ft_insert_str(result, str, ft_strlen(result));
    return result;
}

// Expande las variables de entorno.
void expand_env_var(t_shell *shell, char **envp)
{
    t_var **list_var;
    int i;
    int j;
    char *key;
    char *status;

    list_var = init_envp(envp);
    i = 0;
    status = ft_itoa(shell->g_status);
    while (shell->full_cmd[i])
    {
        j = 0;
        if (shell->full_cmd[i][0] != '\'')
        {
            while (shell->full_cmd[i][j])
            {
                if (shell->full_cmd[i][j] == '$' && !shell->full_cmd[i][j + 1])
                    shell->full_cmd[i][j] = '$';
                else if (shell->full_cmd[i][j] == '$')
                {
                    if (shell->full_cmd[i][j + 1] == '?')
                    {
                        shell->full_cmd[i] = ft_delete_str(shell->full_cmd[i], j, j + 1);
                        shell->full_cmd[i] = ft_insert_str(shell->full_cmd[i], status, j);
                        j++;
                    }
                    else
                    {
                        key = find_varname(shell->full_cmd[i], j + 1);
                        shell->full_cmd[i] = ft_delete_str(shell->full_cmd[i], j, j + ft_strlen(key));
                        shell->full_cmd[i] = ft_insert_str(shell->full_cmd[i], get_var(list_var, key), j);
                        free(key);
                    }
                }
                j++;
            }
            if (strchr(shell->full_cmd[i], '\"'))
                shell->full_cmd[i] = replace_key_x_value(list_var, shell->full_cmd[i], shell);

        }
    i++;
    }
    free(status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:05:40 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 16:35:26 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Extrae la parte de un array que está encerrada entre comillas dobles.
*/
char *process_dq(char *prompt, int *pos, t_shell *shell)
{
    (void)*shell;
    char *word;
    int w_pos = 0;
    int dq_counter = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    //(*pos)++; // Saltar la comilla inicial
    while (prompt[*pos] && dq_counter != 2)
    {
        if (prompt[*pos] == '\"')
            dq_counter++;
        //if (prompt[*pos] == '$')
            //mini_expand_env_var(prompt, shell->env, pos, shell);
        //else
        //{        
            aux[w_pos++] = prompt[*pos];
            (*pos)++;
        //}
    }
    //(*pos)++; // Saltar la comilla de cierre
    word = ft_strdup(aux);
    free(aux);
    return word;
}

char *process_sq(char *prompt, int *pos)
{
    char *word;
    int w_pos = 0;
    int dq_counter = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    //(*pos)++; // Saltar la comilla inicial
    while (prompt[*pos] && dq_counter != 2)
    {
        if (prompt[*pos] == '\'')
            dq_counter++;
        //if (prompt[*pos] == '$')
            //mini_expand_env_var(prompt, shell->env, pos, shell);
        //else
        //{        
            aux[w_pos++] = prompt[*pos];
            (*pos)++;
        //}
    }
    //(*pos)++; // Saltar la comilla de cierre
    word = ft_strdup(aux);
    free(aux);
    return word;
}


/*
	Extrae la parte de un array que está encerrada entre comillas simples,
	y ademas no las interpreta, ya que con las sq se imprime tal cual.

char *process_sq(char *prompt, int *pos)
{
    char *word;
    int w_pos = 0;
    char *aux = ft_calloc(ft_strlen(prompt) - *pos + 1, sizeof(char));

    while (prompt[*pos] && prompt[*pos] != '\'')
    {    
            aux[w_pos++] = prompt[*pos];
            (*pos)++;
    }
    word = ft_strdup(aux);
    free(aux);
    return word;
}
*/
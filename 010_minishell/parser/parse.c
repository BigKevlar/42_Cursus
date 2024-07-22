/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 17:59:50 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Calcula la longuitud de una palabra dentro de prompt, empezando en pos y
	terminando cuando encuentre un espacio, "|", "<" o ">".
*/
int	strlen_end_word(char *prompt, int pos)
{
	int	w_len;

	w_len = 0;
	while (prompt[pos] && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '<' && prompt[pos] != '>')
	{
		w_len++;
		pos++;
	}
	return (w_len);
}

/*
	Separamos por los caracteres que estamos validando, teniendo en cuenta
	los espacios y las comillas que pudieran haber al principio.
*/
char	**ft_strd_new(char *str)
{
	char	**new;

	new = ft_calloc(sizeof(char *), 2);
	new[0] = ft_strdup(str);
	return (new);
}

char **super_split(char *prompt, t_shell *shell)
{
    int pos = 0;
    char *aux;
    char **new = NULL;

    while (prompt[pos])
    {
        while (prompt[pos] == ' ')
            pos++;
        if (prompt[pos] == '\"')
            aux = process_dq(prompt, &pos, shell);
        else if (prompt[pos] == '\'')
            aux = process_sq(prompt, &pos);
        else if (prompt[pos] == '|')
            aux = process_pipe(prompt, &pos);
        else if (prompt[pos] == '<')
            aux = process_red1(prompt, &pos);
        else if (prompt[pos] == '>')
            aux = process_red2(prompt, &pos);
        else
            aux = process_char(prompt, &pos);
        if (aux && *aux)
        {
            if (!new)
                new = ft_strd_new(aux);
            else
                new = ft_strd_add(new, aux);
        }
        free(aux);
    }
    return new;
}

char	**parse_input(char *prompt, t_shell *shell)
{
	char	**cmd;

	cmd = super_split(prompt, shell);
	if (prompt[ft_strlen(prompt) - 1] == ' ')
		cmd = ft_strd_lastdel(cmd);
	return (cmd);
}

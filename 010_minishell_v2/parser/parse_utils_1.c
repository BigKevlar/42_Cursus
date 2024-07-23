/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/23 12:40:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Extrae una parte de caracteres que sean pipes consecutivos.
*/
char	*process_pipe(char *prompt, int *pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	aux_pos = *pos;
	len = 0;
	while (prompt[aux_pos] == '|')
	{
		aux_pos++;
		len++;
	}
	aux = ft_substr(prompt, *pos, len);
	*pos += len;
	return (aux);
}

/*
	Extrae una parte de caracteres que sean "<" consecutivos.
*/
char	*process_red1(char *prompt, int *pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	aux_pos = *pos;
	len = 0;
	while (prompt[aux_pos] == '<')
	{
		aux_pos++;
		len++;
	}
	aux = ft_substr(prompt, *pos, len);
	*pos += len;
	return (aux);
}

/*
	Extrae una parte de caracteres que sean ">" consecutivos.
*/
char	*process_red2(char *prompt, int *pos)
{
	char	*aux;
	int		aux_pos;
	int		len;

	aux_pos = *pos;
	len = 0;
	while (prompt[aux_pos] == '>')
	{
		aux_pos++;
		len++;
	}
	aux = ft_substr(prompt, *pos, len);
	*pos += len;
	return (aux);
}

/*
	Extrae una subcadena de caracteres "normales" consecutivos.
*/
char	*process_char(char *prompt, int *pos)
{
	int		aux_pos;
	char	*aux;
	char	*word;

	aux_pos = *pos;
	while (prompt[*pos] && prompt[*pos] != ' ' && prompt[*pos] != '|'
		&& prompt[*pos] != '<' && prompt[*pos] != '>')
	{
		if (prompt[++(*pos)] == '=')
		{
			aux = ft_substr(prompt, aux_pos, *pos - aux_pos + 1);
			(*pos)++;
			if (prompt[*pos] == '\"')
				word = process_dq(prompt, pos);
			else if (prompt[*pos] == '\'')
				word = process_sq(prompt, pos);
			else
				word = process_char(prompt, pos);
			word = ft_strjoin(aux, word);
			free(aux);
			return (word);
		}
	}
	word = ft_substr(prompt, aux_pos, *pos - aux_pos);
	return (word);
}

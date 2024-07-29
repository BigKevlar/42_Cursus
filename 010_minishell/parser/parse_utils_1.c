/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 13:54:12 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Procesa una parte de caracteres que sean pipes consecutivos.
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
	Procesa una parte de caracteres que sean "<" consecutivos.
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
	Procesa una parte de caracteres que sean ">" consecutivos.
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
	Procesa una subcadena de caracteres "normales" consecutivos.
*/
char	*process_char(char *prompt, int *pos)
{
	char	*word;
	char	*aux1;
	char	*aux2;

	aux2 = ft_strdup("");
	while (prompt[*pos] && prompt[*pos] != ' ' && prompt[*pos] != '|'
		&& prompt[*pos] != '<' && prompt[*pos] != '>')
	{
		if (prompt[*pos] == '\"')
			word = process_dq(prompt, pos);
		else if (prompt[*pos] == '\'')
			word = process_sq(prompt, pos);
		else
			word = ft_substr(prompt, (*pos)++, 1);
		aux1 = ft_strjoin(aux2, word);
		free(aux2);
		free(word);
		aux2 = aux1;
	}
	return (aux2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:46:21 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 00:52:08 by jmartos-         ###   ########.fr       */
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
	int aux_pos = ft_strlen(prompt) - *pos;
	char *aux = ft_calloc(aux_pos + 2, sizeof(char));
	
	aux_pos = 0;
	while (prompt[*pos] && prompt[*pos] != ' ' && prompt[*pos] != '|'
		&& prompt[*pos] != '<' && prompt[*pos] != '>')
	{
			aux[aux_pos++] = prompt[*pos];
			(*pos)++;
	}
	//aux[aux_pos] = '\0';
	char *word = ft_strdup(aux);
	free(aux);
	return (word);
}

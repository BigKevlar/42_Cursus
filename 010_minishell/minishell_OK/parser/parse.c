/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:59:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 22:04:07 by jmartos-         ###   ########.fr       */
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
	while (prompt[pos]
		&& prompt[pos] != ' ' && prompt[pos] != '|'
		&& prompt[pos] != '<' && prompt[pos] != '>')
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

/*
	Segunda parte de super-Split.
*/
char	*process_token(char *prompt, int *pos)
{
	char	*aux;

	aux = NULL;
	while (prompt[*pos] == ' ')
		(*pos)++;
	if (prompt[*pos] == '\"')
		aux = process_dq(prompt, pos);
	else if (prompt[*pos] == '\'')
		aux = process_sq(prompt, pos);
	else if (prompt[*pos] == '|')
		aux = process_pipe(prompt, pos);
	else if (prompt[*pos] == '<')
		aux = process_red1(prompt, pos);
	else if (prompt[*pos] == '>')
		aux = process_red2(prompt, pos);
	else
		aux = process_char(prompt, pos);
	return (aux);
}

/*
	Nuestro Super_split: separamos el prompt por grupos de string.
*/
char	**super_split(char *prompt)
{
	int		pos;
	char	*aux;
	char	**new;

	pos = 0;
	new = NULL;
	while (prompt[pos])
	{
		aux = process_token(prompt, &pos);
		if (aux && *aux)
		{
			if (!new)
				new = ft_strd_new(aux);
			else
				new = ft_strd_add(new, aux);
		}
		free(aux);
	}
	return (new);
}

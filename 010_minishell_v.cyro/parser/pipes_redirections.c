/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 21:34:18 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/23 13:59:46 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
	Comprobamos que no haya un pipe en el primer caracter valido.
*/
int	check_first_pipe(char *prompt)
{
	int	pos;

	pos = 0;
	while (prompt[pos] == ' ' || prompt[pos] == '\t')
		pos++;
	if (prompt[pos] == '|')
		return (0);
	return (1);
}

/*
	Comprobamos que las combinaciones de pipes y redirecciones son correctas.
*/
int	check_mixes(char *prompt, int *pos)
{
	if (prompt[*pos] == '<')
	{
		if (prompt[*pos + 1] == '<' || prompt[*pos + 1] == '>')
			*pos += 2;
		else
			*pos += 1;
	}
	else if (prompt[*pos] == '>')
	{
		if (prompt[*pos + 1] == '>')
			*pos += 2;
		else
			*pos += 1;
	}
	while (prompt[*pos] == ' ' || prompt[*pos] == '\t')
		*pos += 1;
	if (prompt[*pos] == '<' || prompt[*pos] == '>' || prompt[*pos] == '|')
		return (0);
	return (1);
}

/*
	Va cambiando el estado de los pipes y redireciones.
*/
void	set_pipe_red(t_pipe_red *value, int flag)
{
	if (flag == 1)
	{
		value->pipe = 1;
		value->red = 0;
	}
	else if (flag == 2)
	{
		value->pipe = 0;
		value->red = 1;
	}
	else if (flag == 3)
	{
		value->pipe = 0;
		value->red = 0;
	}
}

/*
	Verificamos que el ultimo caracter valido no sea ni "|" ni "<" ni ">".
*/
int	check_last_pipe_red(char *prompt)
{
	int	pos;

	if (ft_strlen(prompt) > 0)
		pos = ft_strlen(prompt) - 1;
	else
		pos = 0;
	while (pos >= 0 && (prompt[pos] == ' ' || prompt[pos] == '\t'))
		pos--;
	if (prompt[pos] && (prompt[pos] == '|'
			|| prompt[pos] == '<' || prompt[pos] == '>'))
		return (0);
	return (1);
}

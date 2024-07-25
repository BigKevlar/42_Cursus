/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:13:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/25 02:51:30 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*dsdf
	Busca en la lista de variables de entorno (list_var) un key (key) y
	devuelve su valor. So no lo encuentra no devuelve nada.
*/
char	*get_var(t_var **list_var, char *key)
{
	int	i;

	i = 0;
	while (list_var[i])
	{
		if (ft_strcmp(list_var[i]->key, key) == 0)
			return (ft_strdup(list_var[i]->value));
		i++;
	}
	return (ft_strdup(""));
}

/*
	Encuentra una variable de entorno dentro de un string (str) a partir
	de una posicion determinada (pos).
*/
char	*find_varname(char *str, int pos)
{
	char	*key;
	int		i;

	i = pos;
	while (str[pos] && (ft_isalnum(str[pos]) || str[pos] == '_'))
		pos++;
	key = ft_strndup(str + i, pos - i);
	return (key);
}

/*
	Borra las comillas, simples o dobles, de un string (str)
	y da lo mismo donde esten.
*/
void	remove_quotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				str[j++] = str[i++];
			i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				str[j++] = str[i++];
			i++;
		}
		else
			str[j++] = str[i++];
	}
	str[j] = '\0';
}

/*

*/
char	*insert_str(char *main, char *piece, size_t pos)
{
	char	*new;
	size_t	new_pos;
	size_t	piece_pos;

	new = ft_calloc(sizeof(char), ft_strlen(main) + ft_strlen(piece) + 1);
	new_pos = 0;
	piece_pos = 0;
	while (new_pos < pos)
	{
		new[new_pos] = main[new_pos];
		new_pos++;
	}
	while (piece[piece_pos])
	{
		new[new_pos] = piece[piece_pos];
		new_pos++;
		piece_pos++;
	}
	while (main[pos])
	{
		new[new_pos] = main[pos];
		new_pos++;
		pos++;
	}
	return (new[new_pos] = '\0', new);
}

char	*delete_str(char *main, size_t start, size_t finish)
{
	size_t	main_pos;
	size_t	len;
	size_t	new_len;
	char	*new;
	size_t	new_pos;

	main_pos = 0;
	len = ft_strlen(main);
	new_len = len - (finish - start + 1);
	new = ft_calloc(sizeof(char), new_len + 1);
	new_pos = 0;
	while (main_pos < start)
		new[new_pos++] = main[main_pos++];
	main_pos = finish + 1;
	while (main_pos < len)
		new[new_pos++] = main[main_pos++];
	new[new_pos] = '\0';
	return (new);
}

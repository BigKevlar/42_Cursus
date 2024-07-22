/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:13:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/22 20:45:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
void	remove_dquotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\"' && str[i] != '\'')
		{
			str[j] = str[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
}

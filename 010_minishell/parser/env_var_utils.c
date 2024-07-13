/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:13:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/13 17:30:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void remove_dquotes(char *str)
{
	int len;

	len = strlen(str);
	if (len > 1 && str[0] == '"' && str[len - 1] == '"')
	{
		// Mueve el contenido hacia la izquierda para sobrescribir la primera comilla
		ft_memmove(str, str + 1, len - 2);
		str[len - 2] = '\0'; // Añade el terminador nulo
	}
}

char *implement_dolar_question(char *str, char *start, char *end, int cmd_exit_status)
{
	char *tmp1;
	char *tmp2;

	tmp1 = ft_strndup(str, start - str);			  // Left side of the var: "hello $?" -> "hello "
	tmp2 = ft_strjoin(tmp1, ft_itoa(cmd_exit_status)); // "hello " + "exit_status" -> "hello 0"
	free(tmp1);
	tmp1 = ft_strjoin(tmp2, end); // "hello 0" + " rest of the string" -> "hello 0 rest of the string"
	free(tmp2);
	ft_printf("tmp1 = %s\n", tmp1);
	return (tmp1);
}

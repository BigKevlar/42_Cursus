/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:52:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 11:26:46 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion imprime en la salida estandar los argumentos que recibe. */

void	ft_echo(char **args)
{
	int	i;
	int	x;
	int	newline;

	newline = 1;
	i = 1;
	x = 1;
	while (args[i] && args[i][0] == '-' && args[i][1] == 'n')
	{
		while (args[i][x] == 'n')
			x++;
		if (args[i][x] != '\0')
			break ;
		newline = 0;
		i++;
	}
	while (args[i])
	{
		ft_putstr_fd(args[i], STDOUT_FILENO);
		if (args[i + 1] && args[i][0] != '\0')
			ft_putstr_fd(" ", STDOUT_FILENO);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
}

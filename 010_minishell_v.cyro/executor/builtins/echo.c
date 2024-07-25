/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:52:32 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/24 02:51:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* Esta funcion imprime en la salida estandar los argumentos que recibe. */

void	ft_echo(char **args, t_shell *shell)
{
	int	i;
	int	x;
	int	newline;

	newline = 1;
	i = 0;
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
		ft_putstr_fd(args[i], shell->fdout);
		if (args[i + 1] && args[i][0] != '\0')
			ft_putstr_fd(" ", shell->fdout);
		i++;
	}
	if (newline)
		ft_putstr_fd("\n", shell->fdout);
}

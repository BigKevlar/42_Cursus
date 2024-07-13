/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:32:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/13 16:37:01 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_SIGINT(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line(); // Nos hemos movido a una nueva linea.
		rl_redisplay(); // Refrescamos el buffer actual de visual de pantalla.
		ft_putstr_fd("  \n", 1); // Pasamos esto al fd 1.
		rl_replace_line("", 0); // Borramos el buffer
		rl_on_new_line(); // Nos movemos de nuevo a una nueva linea.
		rl_redisplay(); // Refrescamos de nuevo buffer para recibir nuevos comandos.
	}
}

// CTRL + 'D': termina el shell.
void	handle_EOF(char *line)
{
    (void)line;
	// AQUI TENEMOS QUE LIBERAR MEMORIA DE TODO SI FUERA NECESARIO.
	exit(0);
}

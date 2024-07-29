/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:32:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/21 19:01:11 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// SIGINT(2) = CTRL + 'C' = cerramos proceso y creamos nueva linea.
// SIGKILL(9) = CTRL + 'D' = termina el shell forzosamente (no se puede manejar)
// SIGQUIT(3) = CTRL + '\' = salida de teclado (no hace nada).
void	handler(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
			// Nos movemos a una nueva línea.
		rl_redisplay();
			// Refrescamos el buffer actual de entrada.
		ft_putstr_fd("  ", 1);
		ft_printf("\n");	
			// Pasamos esto al fd 1.
		rl_replace_line("", 0);	
			// Borramos el buffer, incluido el ^C.
		rl_on_new_line();
			// Nos movemos de nuevo a una nueva línea.
		rl_redisplay();
			// Redibuja la línea de entrada, para recibir nuevos comandos.
		rl_replace_line("", 0);	
			// Borramos el buffer, incluido el ^C.
		g_error = 130;
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
			// Nos movemos a una nueva línea.
		rl_replace_line("  ", 0);	
			// Borramos el buffer, incluido el ^\.
		rl_redisplay();
			// Redibuja la línea de entrada, que es nada.
		g_error = 131;
	}
}

void	if_signal(void)
{
	struct sigaction	sig;

	sig.sa_handler = &handler;
	sig.sa_flags = SA_RESTART;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGINT, &sig, NULL);
	sigaction(SIGQUIT, &sig, NULL);
}

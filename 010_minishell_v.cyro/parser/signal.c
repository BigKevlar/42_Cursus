/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:32:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/23 15:37:20 by jmartos-         ###   ########.fr       */
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
		rl_redisplay();
		ft_putstr_fd("  ", 1);
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_replace_line("  ", 0);
		rl_redisplay();
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:16:19 by jmartos-          #+#    #+#             */
/*   Updated: 2023/09/04 19:33:39 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Este "handler" sirve tanto para señales de SIGUSR1 como de SIGUSR2. */
void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	word;

	(void)context;
	if (signal == SIGUSR1)
		word = word | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", word);
		if (word == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		bit = 0;
		word = 0;
	}
	kill(info->si_pid, SIGUSR2);
	return ;
}

/* DESAROLLO
*/
/* Esta es la parte de servidor. Vamos a "arrancarlo".
*/
/* Como dice el subject, lo primero en el servidor es mostrar su pid.
Para ello creamos la variable "pid" con el tipado "pid_t" de la libreria
de C (pid_t = int) y le metemos el pid del servidor con la funcion
"getpid" para imprimirlo por pantalla a continuacion con "ft_printf".
*/
/* Luego vamos a inicializar a 0 con la funcion  de C "sigemptyset()"
el valor de "sa_mask" (señales bloquedas) dentro de nuestra estructura.
Esto se hace para que no se interrumpan otras señales mientras manejamos
las nuestras, "SIGUSR1" y "SIGUSR2".
*/
/* Ahora vamos a configurar las flags (banderas) de nuestra estructura.
significa que vamos a recibir informacion mediante "handler", al que le
pasaremos por parametros: el numero de señal, el mensaje y un puntero vacio.
Este "handler"
*/
int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("ProcessID del servidor: %d\n", pid);
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}

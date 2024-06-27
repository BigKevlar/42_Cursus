/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:16:19 by jmartos-          #+#    #+#             */
/*   Updated: 2023/09/08 16:35:07 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* En este "handler" sirve tanto para señales SIGUSR1 como SIGUSR2. */
void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static char	byte;

	(void)context;
	if (signal == SIGUSR1)
		byte = byte | (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", byte);
		if (byte == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		bit = 0;
		byte = 0;
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
/* A partir de aqui vamos a configurar el manejo de señales, que es un poco
lioso de explicar, pero basicamente las siguientes lineas vienen
preconfiguradas y hay que ponerlas asi para que funciones nuestro "handler"
*/
/* Inicializamos a 0 con la funcion de C "sigemptyset()" el valor de
"sa_mask" (señales bloquedas) dentro de nuestra estructura.
Esto se hace para que no se interrumpan otras señales mientras manejamos
las nuestras, "SIGUSR1" y "SIGUSR2".
*/
/* SA_SIGINFO lo establecemos en las flags (banderas) de nuestra estructura,
que usaremos para recibir 3 valores mediante un "handler" de sigaction
 que configuraremos: señal, valor/info de cliente y un puntero vacio.
*/
/* Con el "handler" configurado para que se llame cada ver que entre una
señal "sigaction" con sus parametros, ya solo queda poner en espera el
proceso con un bucle infinito y la funcion "pause" (magia).
*/
int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("ProcessID del servidor: %d\n", pid);
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO | SA_NODEFER;
	sig.sa_sigaction = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}

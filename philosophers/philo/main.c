/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/25 19:06:03 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
La estructura de parametros recibida para el programa sera la siguiente:

	Input:	./philo 5 800 200 200 [5]

				nombre_del_programa
					numeros_de_filosofos
						tiempo_para_morir
							tiempo_en_comer
								tiempo_de_dormir
									[limite_de_comidas] (opcional)
*/

void leaks()
{
	system("leaks -q philo");
}

int	main(int ac, char **av)
{
	atexit(leaks);
	t_table	*table;

	table = ft_calloc((sizeof(t_table)), 1);	
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
			return (0);
		if (check_int(av))
			return (0);
		if (table_init(ac, av, table) || philo_init(table)
			|| fork_init(table))
			return (0);
		if (table->philo_count == 1)
		{	
			only_one_philo(table->philos);
			return (0);
		}
		if (start_game(table) == 1)
			return (0);
	}
	the_end(table);
	printf(PURPLE"PROGRAM FINISHED\n"END);
	return (0);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Vamos a comentar la funcion leaks por si el corrector quiere usarla.
	En el main declaramos nuestra estructura "table", reservando memoria con 
	ft_calloc (utils_libft.c), y recibiremos 5 o 6 parametros y hacemos lo
	siguiente, sin enrollarnos mucho porque luego dessarrolamos en cada una):
		
		1- Parseamos los argumentos para que no se introduzcan caracteres no
		permitidos.
		
		2- Tambien parseamos que respete la longuitud maxima y minima de long.
		
		3- Iniciamos nuestras 2 estructuras y los mutex.
		
		4- Si solo recibimos por parametros 1 solo philo llamamos a la funcion
		exclusiva para ello.
		
		5- En cualquier otro caso iniciamos el programa principal.
		
		6- Al final del todo finalizamos programa liberando memoria y printeamos.

	Input:	
	
		av[0] = programa
		av[1] = numeros_de_filosofos
		av[2] = tiempo_para_morir
		av[3] = tiempo_en_comer
		av[4] = tiempo_de_dormir
		av[5] = [limite_de_comidas] (opcional)
		
	Ej.:
						ms	ms	ms
		./philo		5	800	200 200 [5]
		
	Para convertir int (seg) a ms se tiene que multiplicar por 1000,
	que significa 10^3 o 1e3.
--------------------------------------------------------------------------------
*/

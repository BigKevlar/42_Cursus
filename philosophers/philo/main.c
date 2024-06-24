/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/24 19:44:46 by jmartos-         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_table	*table;

	table = ft_calloc((sizeof(t_table)), 1);	
	if (ac == 5 || ac == 6)
	{
		if (check_args(av))
			return (0);
		if (check_int(av))
			return (0);
		if (table_init(ac, av, table) || fork_init(table)
			|| philo_init(table))
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
	printf(PINK"FIN\n"END);
	return (0);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	En el main tenemos que hacer lo siguiente, tras haber comprobado que podemos
	recibir 5 o 6 parametros:
		1- Parsear los parametros con la 
--------------------------------------------------------------------------------
*/

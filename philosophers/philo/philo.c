/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/17 15:41:55 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
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
	t_table	table;
	
	if (ac == 5 || ac == 6)
	{
		parse_input(&table, av);
		table_init(&table);
		table_start(&table);
	}
	else
		error_exit("ERROR IN PARAMETERS");
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:08 by jmartos-          #+#    #+#             */
/*   Updated: 2024/06/11 23:49:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	El main es un TL;DR del progama???
	Input:	./philo
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
		
	}
	else
		error_and_exit("ERROR");
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

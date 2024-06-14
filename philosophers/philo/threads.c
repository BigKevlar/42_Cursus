/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:07:32 by jmartos           #+#    #+#             */
/*   Updated: 2024/06/14 22:51:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
	Control para los estados de los hilos.

	Threads functions (pthread.h): 
		CREATE
		JOIN
		DETACH
*/

static void	check_thread_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EAGAIN == status)
		error_exit("ERROR! CANT CREATE NEW THREAD");
	else if	(EINVAL == status && CREATE == opcode)
		error_exit("ERROR! INVALID ATTR");
	else if	(EINVAL == status && (JOIN == opcode || DETACH == OPCODE))
		error_exit("ERROR! THE THREAD IN NOT JOINABLE");
	else if (EDEADLK == status)
		error_exit("ERROR! DEADLOCK DETECTED");
	else if (EPERM == status)
		error_exit("ERROR! DONT HAVE ENOUGHT PERMISSIONS");
	else if	(ESRCH == status)
		error_exit("ERROR! NO THREADS COULD BE FOUND");	
}

void	thread_handle(pthread *thread, void *funct, void *data, t_opcode opcode)
{
	if (CREATE == opcode)
		check_thread_error(pthread_create(thread, NULL, funct, data), opcode);
	else if (JOIN == opcode)
		check_thread_error(pthread_join(*thread, NULL), opcode);
	else if (DETACH == opcode)
		check_thread_error(pthread_detach(*thread, opcode));
	else
		error_exit("ERROR! OPCODE THREAD HANDLE WRONG (USE 'CREATE', 'JOIN' OR 'DETACH').");		
}

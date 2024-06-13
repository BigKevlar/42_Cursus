/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos <jmartos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:07:32 by jmartos           #+#    #+#             */
/*   Updated: 2024/06/13 20:46:20 by jmartos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 
	Control para los estados de los mutex.

	Mutex functions (pthread.h): 
		LOCK
		UNLOCK
		INIT
		DESTROY
*/

static void	check_mutex_error(int status, t_opcode opcode)
{
	if (0 == status)
		return ;
	if (EINVAL == status && (LOCK == opcode || UNLOCK == opcode))
		error_exit("ERROR! INVALID MUTEX");
	else if	(EINVAL == status && INIT == opcode)
		error_exit("ERROR! INVALID ATTR");
	else if (EDEADLK == status)
		error_exit("ERROR! DEADLOCK");
	else if (EPERM == status)
		error_exit("ERROR! CURRENT THREAD NOT HOLDING A LOCK ON MUTEX");
	else if (ENOMEN == status)
		error_exit("ERROR! CURRENT PROCESS DOESNT HAVE MEMORY TO CREATE MUTEX");
	else if (EBUSY == status)
		error_exit("ERROR! MUTEX LOCKED");	
}

void	mutex_handle(t_mtx *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		check_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		check_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		check_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		check_mutex_error(ptrhead_mutex_destroy(mutex), opcode);
	else
		error_exit("ERROR! OPCODE MUTEX HANDLE WRONG (USE 'LOCK', 'UNLOCK', 'INIT' OR 'DESTROY').");		
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 19:07:32 by jmartos           #+#    #+#             */
/*   Updated: 2024/06/17 17:32:40 by kevlar           ###   ########.fr       */
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
	else if (EBUSY == status)
		error_exit("ERROR! MUTEX LOCKED");	
}

void	mutex_handle(pthread_mutex_t *mutex, t_opcode opcode)
{
	if (LOCK == opcode)
		check_mutex_error(pthread_mutex_lock(mutex), opcode);
	else if (UNLOCK == opcode)
		check_mutex_error(pthread_mutex_unlock(mutex), opcode);
	else if (INIT == opcode)
		check_mutex_error(pthread_mutex_init(mutex, NULL), opcode);
	else if (DESTROY == opcode)
		check_mutex_error(pthread_mutex_destroy(mutex), opcode);
	else
		error_exit("ERROR! OPCODE MUTEX HANDLE WRONG (USE 'LOCK', 'UNLOCK', 'INIT' OR 'DESTROY').");		
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:53:39 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:26:02 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Cuenta el número de nodos de una lista.#*/
int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst)
	{
		cont++;
		lst = lst->next;
	}
	return (cont);
}

/*DESARROLLO*/
/*Creamos un contador a 0 que aumentara mientras exista la lista.
"lst", que es el primer puntero de la lista, va siendo actualiado por el
del siguiente nodo y asi consecutivamente, y al final devuelve el contador
con todos los nodos por los que paso.*/
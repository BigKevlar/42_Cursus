/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:59:31 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/06 15:39:31 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Itera (avanza) en la lista "lst" y aplica la función "f" en el
contenido de cada nodo.#*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*DESARROLLO*/
/*Mientras la lista exista/no este vacia le vamos a ir aplicando la
funcion "f" al contenido de, en este caso, el primer nodo.
Luego con "lst = lst->next" vamos actualizando el puntero al nodo de
la lista y vamos avanzando de nodo hasta llegar al ultimo.*/
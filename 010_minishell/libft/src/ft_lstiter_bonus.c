/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:59:31 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:25:52 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

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
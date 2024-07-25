/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:15:42 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:25:45 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Elimina y libera el nodo "lst" dado y todos los consecutivos de ese nodo,
utilizando la función "del" y free. Al final, el puntero a la lista
debe ser NULL.#*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (lst && *lst != NULL)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}

/*DESARROLLO*/
/*Creamos un nodo auxiliar "aux".
Comprobamos si la lista "lst" existe y si a donde apunta no es nulo.
Si se cumple esta condicion guardamos en nuestro nodo auxiliar el puntero
al siguiente nodo, y luego ejecutamos nuestra funcion anterior "ft_lstdelone"
para borrar su contenido y liberar la memoria de su contenido.
Despues actualizamos el puntero al siguiente nodo usando en nodo auxiliar
en el que habiamos copiado el puntero al siguiente nodo.
Al final de la lista actualizamos el puntero de la misma a NULL, aunque
realmente no haria falta porque el ultimo nodo que
se copio en la lista ya era NULL, pero nos aseguramos de ello.
Vamos, que esta funcion borra todos los nodos, libera sus memorias, y deja
el puntero next de la lista en NULL.*/
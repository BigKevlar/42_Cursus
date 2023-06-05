/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:15:42 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/05 16:25:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Elimina y libera el nodo "lst" dado y todos los consecutivos de ese nodo,
utilizando la función "del" y free. Al final, el puntero a la lista
debe ser NULL.#*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	while (lst && *lst != NULL)
	{
		ft_lstdelone(*lst, del);
		(*lst)->next = NULL;
	}
}

/*DESARROLLO*/
/*La funcion empieza comprobando si el nodo "lst" existe y si no es nulo.
Si se cumple esta condicion ejecutamos nuestra funcion anterior "ft_lstdelone"
para borrar su contenido y liberar la memoria de su contenido,
pero no tocar su next.
Al final actualizamos la direccion de "lst" con NULL.
Vamos, que esta funcion borra todos los nodos, libera sus memorias, y deja
el puntrero next de la lista en NULL.*/
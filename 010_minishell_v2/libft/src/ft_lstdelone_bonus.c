/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:08:44 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:25:49 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Toma como parámetro un nodo "lst" y libera la memoria del contenido
utilizando la función "del" dada como parámetro, además de liberar el nodo.
La memoria de "next" no debe liberarse.#*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/*DESARROLLO*/
/*"lst" corresponde al nodo que queremos modificar. Si existe, ejecutamos la
funcion "del" para liberar la direccion memoria del contenido de ese nodo, y
ejecutamos un free a la memoria que guarda el puntero del propio nodo. Eso si,
!!!no liberamos la de su puntero que apunta al siguiente nodo!!!*/
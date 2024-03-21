/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:01:10 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:25:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Itera (avanza) en la lista "lst" y aplica la función "f" al contenido de
cada nodo. Crea una lista resultante de la aplicación correcta y sucesiva
de la función "f" sobre cada nodo. La función ’del’ se utiliza para eliminar
el contenido de un nodo, si hace falta.#*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (!aux)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, aux);
		lst = lst->next;
	}
	return (new_lst);
}

/*DESARROLLO*/
/*Vamos a crear dos variables tipo nodo. Una que apuntara a la
nueva lista"new_lst", y otra en la que guardaremos los nuevos nodos.
Primero verificamos si la lista "lst", la funcion "f" o la
funcion de eliminar "del" son nulas, para terminar el programa con NULL.
Si no, inicializamos nuestra nueva lista con el puntero en NULL (vacia)
e iniciamos el bucle en el que mientras exista la lista la recorrera.
El nodo auxiliar "aux" es creado con el contenido de cada nodo y
la funcion ya aplicada.
Retorna NULL si el nodo no se ha creado bien, limpiando la nueva
lista y devolviendo NULL.
Si se creo correctamente, con ft_lstadd_back añade el nuevo nodo "aux"
al final de la nueva lista "new_lst", y se avanza al siguiente nodo de
la lista normal, y asi sucesivamente hasta que ya no haya mas nodos
en la lista normal, todos esten creados uno tras otro en la nueva,
se sale del bucle y se devulve la nueva lista "new_lst".
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:01:10 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/05 16:34:27 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Itera (avanza) en la lista "lst" y aplica la función "f" al contenido de
cada nodo. Crea una lista resultante de la aplicación correcta y sucesiva
de la función "f" sobre cada nodo. La función ’del’ se utiliza para eliminar
el contenido de un nodo, si hace falta.#*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (!aux)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, aux);
		lst = lst->next;
	}
	return (result);
}

/*DESARROLLO*/

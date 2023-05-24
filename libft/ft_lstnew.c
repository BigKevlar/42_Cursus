/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:12:48 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/23 14:08:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
Un nodo es una estructura de listas enlazadas que se llaman entre si.
En la parte de...
	new_node->content = content;
	new_node->next = NULL;
... se hace referencia a que, el valor pasado por parametro pasara al campo
"content" del nuevo nodo creado, y el NULL en "next" indica que va a moverse
NULL a "next".
*/
/*
Se crea un nuevo nodo utilizando malloc. La variable miembro "content" se
inicializa con el contenido del parámetro "content". La variable "next" con NULL.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

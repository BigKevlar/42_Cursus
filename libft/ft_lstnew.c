/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:12:48 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/03 14:05:16 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Se crea un nuevo nodo "node" utilizando malloc y le damos tipado "t_list", 
pasando asi a ser una estructura de la lista. La variable miembro
"content" se inicializa con el contenido del parámetro "content",
(que estaria vacia de momento) y la variable "next" se inicia con NULL,
porque se entiende que seria el ultimo mienmbro de la lista, por lo que
no apunta a nadie (aun). Al final devolvemos lo que nos pide, un nuevo nodo.#*/
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

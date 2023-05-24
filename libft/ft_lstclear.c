/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:15:42 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/24 12:40:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
Elimina y libera el nodo "lst" dado y todos los consecutivos de ese nodo,
utilizando la función "del" y free. Al final, el puntero a la lista
debe ser NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	while (lst && *lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:53:39 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/23 12:54:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
Cuenta el número de nodos de una lista.
*/
int	ft_lstsize(t_list *lst)
{
	size_t	cont;

	cont = 0;
	while (lst)
		lst = lst->next;
		cont++;
	return (cont);
}

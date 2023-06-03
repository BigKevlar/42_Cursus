/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:53:39 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/03 14:34:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Cuenta el número de nodos de una lista. La parte de "lst = lst->next" va
avanzando y va aumentando el contador para luego devolverlo.#*/
int	ft_lstsize(t_list *lst)
{
	size_t	cont;

	cont = 0;
	while (lst)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:06:43 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:25:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Añade el nodo "new" al principio de la lista "lst". Con "**lst" nos
referimos a un puntero que apunta al puntero del primer nodo de la lista,
y "new" es el puntero del nuevo nodo que enviaremos al principio
de la lista.#*/
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst || new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*DESARROLLO*/
/*Mientras el primer puntero al que apunta la lista no sea nulo (cosa que
significaria que la lista estaria vacia) y que el puntero de new tampoco
sea nulo (acordarse que la condicion || es una variable de cortocircuito)
se actualiza para que apunte el primer puntero de lista a "new"
(que es al que apunta el puntero de "lst"), y luego el primer puntero
de la lista tambien se actualiza para que apunte a "new",
el nuevo primero.*/
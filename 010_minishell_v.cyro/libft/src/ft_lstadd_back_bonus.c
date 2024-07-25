/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:13:18 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:25:40 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Añade el nodo "new" al final de la lista "lst".#*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*final;

	if (!*lst)
		*lst = new;
	else
	{
		final = ft_lstlast(*lst);
		final->next = new;
	}
}

/*DESARROLLO*/
/*Creamos una nueva variable tipo nodo llamada "final"
(donde guardaremos la ultima posicion actual de la lista),
y comprobamos que la lista no esta vacia (si asi fuese pues el puntero al
que apuntaria "lst" seria la direccion de "new", que seria el primer nodo).
Tras la verificacion, nos valemos de la funcion "ft_ltslast" para encontrar
la direccion del puntero de la ultima posicion de la lista y guardarla en
"final".
Finalmente enlazamos la direccion de "new" al puntero "next" de "final",
quedando asi "final" como el penultimo, y "new" como ultimo (con next NULL).*/
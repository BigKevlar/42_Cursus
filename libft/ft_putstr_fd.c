/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:57:24 by jmartos-          #+#    #+#             */
/*   Updated: 2023/06/01 18:57:11 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Envía la string "s" al descriptor "fd".#*/
void	ft_putstr_fd(char *s, int fd)
{
	int	cont;

	cont = 0;
	while (s[cont])
	{
		write (fd, &s[cont], 1);
		cont++;
	}
}
/*Tener en cuenta lo siguiente de "fd, &c, 1": el primer dato es el
descriptor (donde se recibira el dato, por ejemplo 1 era la impresion
en terminal), el segundo dato es el que recoge propiamente la funcion write
para operar con el, y el ultimo dato es el tamaño del dato a utilizar
(en este caso es 1 porque un solo caracter ocupa 1 byte).
*/

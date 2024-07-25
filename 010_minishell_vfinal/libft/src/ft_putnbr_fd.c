/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:01:14 by jmartos-          #+#    #+#             */
/*   Updated: 2024/03/21 18:27:07 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /*LIBRERIA CUSTOM "jmartos-"*/

/*#Envía el numero "n" al descriptor "fd", seguido de un salto de linea.#*/
void	ft_putnbr_fd(int n, int fd)
{
	char	chr;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		chr = '0' + n % 10;
	}
	else
		chr = '0' + n;
	write(fd, &chr, 1);
}
/*Tener en cuenta lo siguiente de "fd, &c, 1": el primer dato es el
descriptor (donde se recibira el dato, por ejemplo 1 era la impresion
en terminal), el segundo dato es el que recoge propiamente la funcion write
para operar con el, y el ultimo dato es el tamaño del dato a utilizar
(en este caso es 1 porque un solo caracter ocupa 1 byte).
*/

/*
int	main(void)
{
	ft_putnbr_fd(0, 1);
	return ;
}
*/
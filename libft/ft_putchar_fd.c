/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:53:21 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/22 13:14:49 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
Envía el carácter "c" al file descriptor "fd" especificado.
*/
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

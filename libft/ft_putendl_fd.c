/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:01:11 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/22 13:22:14 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
Envía la string "s" al file descriptor "fd" dado, seguido de un salto de linea.
*/
void	ft_putendl_fd(char *s, int fd)
{
	size_t	cont;

	cont = 0;
	while (s[cont])
	{
		write (fd, &s[cont], 1);
		cont++;
	}
	write (fd, "\n", 1);
}

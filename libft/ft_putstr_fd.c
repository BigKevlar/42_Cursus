/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 12:57:24 by jmartos-          #+#    #+#             */
/*   Updated: 2023/05/22 13:21:02 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h" /*LIBRERIA CUSTOM*/

/*
(DESCRIPCION)
Envía la string "s" al file descriptor "fd" especificado.
*/
void	ft_putstr_fd(char *s, int fd)
{
	size_t	cont;

	cont = 0;
	while (s[cont])
	{
		write (fd, &s[cont], 1);
		cont++;
	}
}

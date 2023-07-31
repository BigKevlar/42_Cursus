/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:06 by jmartos-          #+#    #+#             */
/*   Updated: 2023/07/31 18:03:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* . */
#include "get_next_line.h"

/* OJO! SOLO SE PUEDE USAR EN LA FUNCION PRINCIPAL: READ, MALLOC Y FREE. */
char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (fd > 0 && BUFFER_SIZE > 0 && read(fd, NULL, 0) >= 0)
	
	return (buffer);
}

/* Main de prueba */
int	main(void)
{
	int	fd;

	fd = open("file.txt", 0);
	printf("%s", get_next_line(3));
	close(fd);
	return (0);
}

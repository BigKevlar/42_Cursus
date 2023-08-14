/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:06 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/14 20:58:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Subfuncion: leerá la primera linea del file descriptor pasado por
parametros hasta que encuentre un salto de linea. */
/* Decripcion: */
static char	*get_line(char *buffer)
{
	char	*line;
	int		counter;

	counter = 0;
	while (buffer[counter] != '\n')
		counter++;
	line = malloc(sizeof(char) * counter + 1);
	if (!line)
		return (NULL);
	counter = 0;
	while (buffer[counter] && buffer[counter] != '\n')
	{
		line[counter] = buffer[counter];
		counter++;
	}
	counter++;
	line[counter] = '\0';
	return (line);
}

/* Funcion principal: le pasamos "fd", que es el archivo de texto
que va a leer, y entregará la linea leida.*/
/* Decripcion: */
char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	int			buffer;

	buffer = read(fd, text, BUFFER_SIZE);
	if (!buffer || buffer <= 0)
		return (NULL);
	line = get_line(text);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*content;

	fd = open("file.txt", O_RDONLY);
	content = get_next_line(fd);
	printf("%s", content);
	free(content);
	close(fd);
	return (0);
}

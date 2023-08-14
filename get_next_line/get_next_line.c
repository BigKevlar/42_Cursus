/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:06 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/14 23:35:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Decripcion: lee byte a byte la primera linea del file descriptor,
hasta que encuentre un salto de linea o finalize la linea. */
/* Analisis: */
static char	*ft_line(char *buffer)
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
	line[counter] = '\0';
	return (line);
}

/* Descripcion: Le pasamos un descriptor de archivo "fd" e imprimira
por pantalla linea por linea el contenido hasta el final. */
/* Analisis: */
char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;
	int			bytes;

	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (NULL);
	bytes = read(fd, text, BUFFER_SIZE);
	if (bytes <= 0)
	{
		free(text);
		return (NULL);
	}
	line = ft_line(text);
	free(text);
	return (line);
}

/*
int	main(void)
{
	int		fd;
	char	*content;

	fd = open("file.txt", O_RDONLY);
	content = get_next_line(fd);
	printf("%s\n", content);
	free(content);
	close(fd);
	return (0);
}
*/

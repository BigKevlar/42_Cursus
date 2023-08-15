/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:06 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/15 17:06:01 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Subfuncion */
/* Decripcion: lee byte a byte la primera linea del file descriptor,
hasta que encuentre un salto de linea o finalize la linea. */
/* Analisis: */
static char	*print_line(char *buffer)
{
	char	*line;
	int		counter;

	line = malloc(sizeof(char) * ft_strlen(buffer) + 1);
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

/* Funcion principal */
/* Descripcion: Le pasamos un descriptor de archivo "fd" e imprimira
por pantalla linea por linea el contenido hasta el final. */
/* Analisis: */
char	*get_next_line(int fd)
{
	char	*text;
	char	*line;
	int		bytes;

	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, text, BUFFER_SIZE);
	}
	if (bytes <= 0)
	{
		free(text);
		return (NULL);
	}
	line = print_line(text);
	free(text);
	return (line);
}

/* Main de prueba */
/*
int	main(void)
{
	int		fd;
	char	*content;

	fd = open("/Users/jmartos-/Documents/42/get_next_line/file.txt", O_RDONLY);
	content = get_next_line(fd);
	while (content != NULL)
	{
		printf("%s\n", content);
		content = get_next_line(fd);
	}
	free(content);
	close(fd);
	return (0);
}
*/

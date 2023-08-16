/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:06 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/16 16:10:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reading_fd(int fd, char *text)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (!(ft_strchr(text, '\n')) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		text = ft_strjoin(text, buffer);
	}
	free(buffer);
	return (text);
}

static char	*printing_line(char *text)
{
	char	*line;
	int		counter;

	line = malloc(sizeof(char) * ft_strlen(text) + 1);
	if (!line)
		return (NULL);
	counter = 0;
	while (text[counter] && text[counter] != '\n')
	{
		line[counter] = text[counter];
		counter++;
	}
	if (text[counter] == '\n')
	{
		line[counter] = '\n';
		counter++;
	}
	line[counter] = '\0';
	return (line);
}

static char	*updating_text(char *text)
{
	char	*str;
	int		cont1;
	int		cont2;

	cont1 = 0;
	cont2 = 0;
	str = malloc(sizeof(char) * (cont1 + 1));
	if (!str)
		return (NULL);
	while (text[cont1] != '\n')
		cont1++;
	while (text[cont1])
	{
		str[cont2] = text[cont1];
		cont1++;
		cont2++;
	}
	str[cont2] = '\0';
	free(text);
	return (str);
}

/* Funcion principal */
/* Descripcion: Le pasamos un descriptor de archivo "fd" e imprimira
por pantalla linea por linea el contenido hasta el final. */
/* Analisis: */
char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	text = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = reading_fd(fd, text);
	line = printing_line(text);
	text = updating_text(text);
	return (line);
}

/* Main de prueba */
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

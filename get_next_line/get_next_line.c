/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:06 by jmartos-          #+#    #+#             */
/*   Updated: 2023/08/03 17:47:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" /* Funcion get_next_line.h "jmartos-". */

/* Subfuncion: leerá e imprimira la primera linea del file descriptor pasado
hasta que encuentre un salto de linea. */
char	*read_one_line_fd(int fd)
{
	char	*line;

	line = read(fd, buffer, BUFFER_SIZE);
}

/* Funcion principal: le pasamos "fd", que es el archivo de texto que va
a leer...*/
char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = read_one_line_fd(fd);
	



}

/*
int	main(void)
{
	int		fd;
	char	*content;

	fd = open("file.txt", O_RDONLY);
	content = get_next_line(3);
	printf("%s", content);
	free(content);
	close(fd);
	return (0);
}
*/












/*
char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (fd > 0 && BUFFER_SIZE > 0 && read(fd, NULL, 0) >= 0)
	
	return (buffer);
}

int	main(void)
{
	int	fd;

	fd = open("file.txt", 0);
	printf("%s", get_next_line(3));
	close(fd);
	return (0);
}
*/
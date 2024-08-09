/*
    Assignment name : get_next_line
    Expected files : get_next_line.c
    Allowed functions: read, free, malloc
    --------------------------------------------------------------------------------

    Write a function named get_next_line which prototype should be:
    char *get_next_line(int fd);


    Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succesion of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

    The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

    In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

    Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

    Caling your function get_next_line in a lop will therefore allow you to read the text avaiable on a file descriptor one line at a time until the end of the text, no matter the size od either the text or one of its lines.

    Make sure that your function behaves wel when it reads from a file, from the standard output, from a redirection, etc...

    No call to another function will be done on the file descriptor between 2 calls of get_next_line. Finally we consider that get_next_line has an undefined behaviour when reading from a binary file.
*/

#define BUFFER_SIZE 424242
#include <fcntl.h> // open, close
/* ESTOS DOS DE ARRIBA QUITARLOS PARA EL EXAMEN. SOLO SIRVEN PARA EL MAIN DE PRUEBA!!! */

#include <unistd.h> // read
#include <stdlib.h> // malloc, free
#include <stdio.h> // EOF

char	*get_next_line(int fd)
{
	char	*line;
	int		pos;
	int		bytes;
	char	chr;

	if (fd < 0)
		return (NULL);
	line = (char *)malloc(10000000);
	if (!line)
		return (NULL);
	pos = 0;
	bytes = read(fd, &chr, 1);
	while (bytes > 0)
	{
		line[pos] = chr;
		pos++;
		if (chr == '\n' || chr == EOF)
			break ;
		bytes = read(fd, &chr, 1);
	}
	line[pos] = '\0';
	if (bytes <= 0 && pos == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

/* RECORDAR QUITAR EL MAIN PARA EL EXAMEN!!! */
int	main(int argc, char **argv)
{
	int		fd;
	int		line;
	char	*string;

	line = 1;
	string = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		string = get_next_line(fd);
		while (string != NULL)
		{
			printf("Line %d - %s\n", line, string);
			string = get_next_line(fd);
			line++;
		}
		if (!string)
			printf("Line %d - (null) EOF\n", line);
		close(fd);
	}
	return (0);
}

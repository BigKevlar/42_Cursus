/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Escribe una función que tome una cadena, la divida en palabras y las devuelva como
una matriz de cadenas terminada en NULL.

Una "palabra" se define como una parte de una cadena delimitada por espacios/tabulaciones/nuevas
o por el inicio/fin de la cadena.

Su función debe declararse como sigue:

char    **ft_split(char *str);
*/

#include <stdlib.h>

char	**ft_split(char *str)
{
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	char **split = (char **)malloc(sizeof(char *) * 256);
	
	if (!split)
		return (NULL);
	while (str[c1] <= 32) //aqui eliminamos los tabs, lineas, espacios y demas cosas que hubieran en el principio.
		c1++;
	while (str[c1] != '\0')
	{
		c2 = 0;
		if (!(split[c3] = (char *)malloc(sizeof(char) * 4096)))
			return (NULL);
		while (!(str[c1] <= 32))
			split[c3][c2++] = str[c1++];
		while (str[c1] == ' ' || str[c1] == '\t' || str[c1] == '\n')
			c1++;
		split[c3][c2] = '\0';
		c3++;
	}
	split[c3] = NULL;
	return (split);
}
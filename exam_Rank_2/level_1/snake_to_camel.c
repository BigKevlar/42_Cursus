/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int c = 0;

	if (ac == 2)
	{
		while (av[1][c] == '_')
			c++;
		while (av[1][c] != '\0')
		{
			if (av[1][c] == '_')
			{
				c++; //saltamos posicion del "_".
				if (av[1][c] >= 'a' && av[1][c] <= 'z') //verificamos si son minusculas y...
					av[1][c] -= 32; //... cambiamos a mayusculas.
			}
			write(1, &av[1][c], 1); //tanto si lo es como si no imprimimos y saltamos de posicion.
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
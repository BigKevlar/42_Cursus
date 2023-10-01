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
#include <stdlib.h>

int	main(int ac, char **av)
{
	int cont = 0;

	if (ac == 2)
	{
		while (av[1][cont] != '\0')
		{
			if (av[1][cont] == '_') //comenzamos el array viendo si encuentra un _ y si es asi la siguiente palabra la pasamos a mayuscula e imprimimos
			{
				cont++;
				av[1][cont] -= 32;
			}
			write(1, &av[1][cont], 1); //tanto si lo es como si no imprimimos y saltamos de posicion.
			cont++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
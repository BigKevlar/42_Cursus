/*
Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that displays a string on the standard output.

The pointer passed to the function contains the address of the string's first
character.

Your function must be declared as follows:

void	ft_putstr(char *str);
*/

#include <unistd.h>

void	ft_putstr(char *str)
{
	int cont = 0;

	while(str[cont] != '\0') //va avanzando el string y escribiendolo.
	{
		write(1, &str[cont], 1);
		cont++;
	}
	return ;
}
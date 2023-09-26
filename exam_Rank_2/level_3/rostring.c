/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int cont = 0;
	int word = 0;


	if (ac >= 2)
	{
		cont = 0;
		while (av[1][cont] == ' ' || av[1][cont] == '\t') // recorremos el string saltando espacios o tabulaciones al comienzo.
			cont++;
		word = cont; // guardamos en word la posicion del comienzo de la primera palabra.
		while (av[1][cont] != '\0') // avanzamos hasta el final.
		{
			while (av[1][cont] != '\0' && (av[1][cont] != ' ' && av[1][cont] != '\t')) // find the next word.
				cont++;
			while (av[1][cont] != '\0' && (av[1][cont] == ' ' || av[1][cont] == '\t')) // find the next word.
				cont++;
			while (av[1][cont] != '\0' && (av[1][cont] != ' ' && av[1][cont] != '\t') && (av[1][cont -1] == ' ' || av[1][cont - 1] == '\t')) // print the word till it reaches last.
			{
				while (av[1][cont] != '\0' && (av[1][cont] != ' ' && av[1][cont] != '\t'))
				{
					write (1, &av[1][cont], 1);
					cont++;
				}
				write (1, " ", 1);
				cont++;
			}
		}
		while (av[1][word] != '\0' && (av[1][word] != ' ' && av[1][word] != '\t')) // print the first word now.
		{
			write (1, &av[1][word], 1);
			word++;
		}
	}
	write(1, "\n", 1);
	return(0);
}
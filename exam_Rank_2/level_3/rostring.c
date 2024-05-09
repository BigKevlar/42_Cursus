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
	int c = 0;
	int first = 0;

	if (ac >= 2)
	{
		c = 0;
		while (av[1][c] == ' ' || av[1][c] == '\t')
			c++;
		first = c;
		while (av[1][c] != '\0')
		{
			while (av[1][c] != '\0' && (av[1][c] != ' ' && av[1][c] != '\t'))
				c++;
			while (av[1][c] != '\0' && (av[1][c] == ' ' || av[1][c] == '\t')) 
				c++;
			while (av[1][c] != '\0' && (av[1][c] != ' ' && av[1][c] != '\t') && (av[1][c -1] == ' ' || av[1][c - 1] == '\t'))
			{
				while (av[1][c] != '\0' && (av[1][c] != ' ' && av[1][c] != '\t'))
				{
					write (1, &av[1][c], 1);
					c++;
				}
				write (1, " ", 1);
				c++;
			}
		}
		while (av[1][first] != '\0' && (av[1][first] != ' ' && av[1][first] != '\t'))
		{
			write (1, &av[1][first], 1);
			first++;
		}
	}
	write(1, "\n", 1);
	return(0);
}

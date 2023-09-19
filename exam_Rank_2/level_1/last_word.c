/*
Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int cont = 0;
	
	if (ac == 2)
	{
		while (av[1][cont] != '\0')
			cont++;
		while((av[1][cont] == " " || av[1][cont] == '\t') && cont != 0)
			cont--;
		while((av[1][cont] != " " || av[1][cont] != '\t') && cont != 0)
			cont--;
		while(av[1][cont] == " " || av[1][cont] == '\t')
			cont++;
		while(av[1][cont] != "\0" && av[1][cont] != " " && av[1][cont] != '\t')
		{
			write(1, &av[1][cont], 1);
			cont++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
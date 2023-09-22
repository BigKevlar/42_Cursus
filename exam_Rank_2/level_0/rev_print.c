/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int		cont = 0;
	char	*str = av[1];

	if (ac == 2)
	{
		while (str[cont])
			cont++;
		cont--;
		while (cont >= 0)
		{
			write(1, &str[cont], 1);
			cont--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
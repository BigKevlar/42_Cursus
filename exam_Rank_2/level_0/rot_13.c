/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	cont = 0;

	if (ac == 2)
	{
		while (av[1][cont] != '\0')
		{
			if ((av[1][cont] >= 'a' && av[1][cont] <= 'm') || (av[1][cont] >= 'A' && av[1][cont] <= 'M'))
				av[1][cont] += 13;
			else if ((av[1][cont] >= 'n' && av[1][cont] <= 'z') || (av[1][cont] >= 'N' && av[1][cont] <= 'Z'))
				av[1][cont] -= 13;
			write (1, &av[1][cont], 1);
			cont++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
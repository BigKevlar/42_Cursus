/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	cont = 0;

	if (ac == 2)
	{
    	while (av[1][cont])
		{
			if (av[1][cont] >= 'a' && av[1][cont] <= 'y')
			{	
				av[1][cont]++;
				write(1, &av[1][cont], 1);
			}
			else if (av[1][cont] >= 'A' && av[1][cont] <= 'Y')
			{
				av[1][cont]++;
				write(1, &av[1][cont], 1);
			}
			else if (av[1][cont] == 'z')
				write(1, "a", 1);
			else if (av[1][cont] == 'Z')
				write(1, "A", 1);
			else
				write(1, &av[1][cont], 1);
			cont++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

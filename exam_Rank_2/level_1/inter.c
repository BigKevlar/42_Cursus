/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int	checker(char *str, char c, int pos)
{
	int	cont = 0;
	while (cont < pos)
	{
		if (str[cont] == c)
			return (0);
		cont++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	cont1 = 0;
	int	cont2 = 0;

	if (ac == 3)
	{
		while(av[1][cont1] != '\0')
		{
			cont2 = 0;
			while(av[2][cont2] != '\0')
			{
				if (av[1][cont1] == av[2][cont2])
				{
					if (checker(av[1], av[1][cont1], cont1))
						write(1, &av[1][cont1], 1);
					break;
				}
				cont2++;
			}
			cont1++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
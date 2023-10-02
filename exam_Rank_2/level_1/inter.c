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

int	check_doubles(char *str, char chr, int pos)
{
	int	c = 0;

	while (c < pos)
	{
		if (str[c] == chr)
			return (0);
		c++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	c1 = 0;
	int	c2 = 0;

	if (ac == 3)
	{
		while(av[1][c1] != '\0')
		{
			c2 = 0;
			while(av[2][c2] != '\0')
			{
				if (av[1][c1] == av[2][c2])
				{
					if (check_doubles(av[1], av[1][c1], c1))
						write(1, &av[1][c1], 1);
					break;
				}
				c2++;
			}
			c1++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
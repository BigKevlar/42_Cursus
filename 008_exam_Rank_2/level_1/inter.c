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
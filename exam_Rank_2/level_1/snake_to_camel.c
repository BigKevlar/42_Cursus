#include <unistd.h>

int	main(int ac, char **av)
{
	int c = 0;

	if (ac == 2)
	{
		while (av[1][c] == '_')
			c++;
		while (av[1][c] != '\0')
		{
			if (av[1][c] == '_')
			{
				c++;
				if (av[1][c] >= 'a' && av[1][c] <= 'z')
					av[1][c] -= 32;
			}
			write(1, &av[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

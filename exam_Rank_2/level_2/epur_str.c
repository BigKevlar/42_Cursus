#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;
	int	mutex = 0;

	if (ac == 2)
	{
		while (av[1][c] == ' ' || av[1][c] == '\t')
			c++;
		while (av[1][c] != '\0')
		{
			if (av[1][c] == ' ' || av[1][c] == '\t')
				mutex = 1;
			else
			{
				if (mutex == 1)
					write(1, " ", 1);
				mutex = 0;
				write(1, &av[1][c], 1);
			}
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

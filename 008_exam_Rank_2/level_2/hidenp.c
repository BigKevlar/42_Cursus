#include <unistd.h>

int	main(int ac, char **av)
{
	int	c1 = 0;
	int	c2 = 0;

	if (ac == 3)
	{
		while (av[1][c1] != '\0' && av[2][c2] != '\0')
		{
			if (av[1][c1] == av[2][c2])
				c1++;
			c2++;
		}
		if (av[1][c1] == '\0')
			write(1, "1", 1);
		if (av[2][c2] == '\0')
			write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}

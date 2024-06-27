#include <unistd.h>

int main(int ac, char **av)
{
	int c = 0;
	int first = 0;

	if (ac >= 2)
	{
		while (av[1][c] == ' ' || av[1][c] == '\t')
			c++;
		first = c;
		while (av[1][c] != '\0')
		{
			while (av[1][c] != '\0' && (av[1][c] != ' ' && av[1][c] != '\t'))
				c++;
			while (av[1][c] != '\0' && (av[1][c] == ' ' || av[1][c] == '\t')) 
				c++;
			while (av[1][c] != '\0' && (av[1][c] != ' ' && av[1][c] != '\t') && (av[1][c - 1] == ' ' || av[1][c - 1] == '\t'))
			{
				while (av[1][c] != '\0' && (av[1][c] != ' ' && av[1][c] != '\t'))
				{
					write (1, &av[1][c], 1);
					c++;
				}
				write (1, " ", 1);
				c++;
			}
		}
		while (av[1][first] != '\0' && (av[1][first] != ' ' && av[1][first] != '\t'))
		{
			write (1, &av[1][first], 1);
			first++;
		}
	}
	write(1, "\n", 1);
	return(0);
}

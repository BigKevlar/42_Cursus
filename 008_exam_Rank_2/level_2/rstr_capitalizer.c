#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int	c = 0;

	while (str[c] != '\0')
	{
		if (str[c] >= 'A' && str[c] <= 'Z')
			str[c] += 32;
		if (str[c + 1] == '\0' || str[c + 1] == ' ' || str[c + 1] == '\t')
		{
			if (str[c] >= 'a' && str[c] <= 'z')
				str[c] -= 32;
		}
		write(1, &str[c], 1);
		c++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	c = 1;

	if (ac < 2)
		write(1, "\n", 1);
	else
	{
		while (c < ac)
		{
			rstr_capitalizer(av[c]);
			c++;
		}
	}
	return (0);
}

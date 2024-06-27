#include <stdio.h>
#include <stdlib.h>

void	is_prime(int num)
{
	int	prime = 2;

	while (num >= prime)
	{
		while (num % prime == 0)
		{
			printf("%d", prime);
			num /= prime;
			if (num >= prime)
				printf("*");
		}
		prime++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2 && atoi(av[1]))
	{
		if (atoi(av[1]) == 1)
			printf("1");
		else
			is_prime(atoi(av[1]));
	}
	printf("\n");
	return (0);
}

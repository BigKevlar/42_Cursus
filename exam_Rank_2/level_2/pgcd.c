#include <stdio.h>
#include <stdlib.h>

void maxcd(unsigned int a, unsigned int b)
{
	if (a > 0 && b > 0)
	{
		while (a != b)
		{
			if (a > b)
				a -= b;
			if (b > a)
				b -= a;
		}
		printf("%d", a);
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
		maxcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}

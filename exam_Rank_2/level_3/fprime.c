/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$
*/

#include <stdio.h>
#include <stdlib.h>

void	is_prime(int n)
{
	int	prime = 2;

	while (n >= prime)
	{
		while (n % prime == 0)
		{
			printf("%d", prime);
			n /= prime;
			if (n >= prime)
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

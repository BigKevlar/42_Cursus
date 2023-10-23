/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
*/

#include <stdio.h> //printf
#include <stdlib.h> //atoi

void maxcd(unsigned int n1, unsigned int n2)
{
	int tmp = n1;
	
	while (tmp > 0)
	{
		if ((n1 % tmp == 0) && (n2 % tmp == 0))
		{
			printf("%d", tmp);
			return ;
		}
		tmp--;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac == 3)
		maxcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
	return (0);
}
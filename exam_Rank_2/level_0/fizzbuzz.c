/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>
*/

#include <unistd.h>

int	main(void)
{
	int	num = 1;
	int	aux1;
	int	aux2;

	while (num <= 100)
	{
		if ((num % 3 == 0) && (num % 5 == 0))
			write(1, "fizzbuzz", 8);
		else if (num % 3 == 0)
			write(1, "fizz", 4);
		else if (num % 5 == 0)
			write(1, "buzz", 4);
		else if (num > 10)
		{
			aux1 = (num / 10) + '0';
			aux2 = (num % 10) + '0';
			write (1, &aux1, 1);
			write (1, &aux2, 1);
		}
		else if (num < 10)
		{
			aux1 = num + '0';
			write(1, &aux1, 1);
		}
		write(1,"\n", 1);
		num++;
	}
	return (0);
}
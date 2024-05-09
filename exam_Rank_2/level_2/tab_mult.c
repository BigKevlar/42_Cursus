/*
Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
*/

#include <unistd.h>

int	miniatoi(char *str)
{
	int	c = 0;
	int	n = 0;

	while (str[c] != '\0')
	{
		n = (n * 10) + (str[c] - '0');
		c++;
	}
	return (n);
}

void	print_num(int n)
{
	char digit;

	if (n >= 10)
		print_num(n / 10);
	digit = (n % 10) + '0';
	write (1, &digit, 1);
}

void	tabmult(int n)
{
	int	num = 1;
	int	res;

	while (num <= 9)
	{
		res = num * n;
		print_num(num);
		write(1, " x ", 3);
		print_num(n);
		write(1, " = ", 3);
		print_num(res);
		write(1, "\n", 1);
		num++;
	}
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 2)
		tabmult(miniatoi(av[1]));
	write(1, "\n", 1);
	return (0);
}

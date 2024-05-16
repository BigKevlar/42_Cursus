/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/

#include <unistd.h>

int	miniatoi(char *str)
{
	int	c = 0;
	int	num = 0;

	while (str[c] != '\0')
	{
		num = (num * 10) + (str[c] - '0');
		c++;
	}
	return (num);
}

void	print_hex(int num)
{
	char	hex[16] = "0123456789abcdef";
	
	if (num >= 16)
		print_hex(num / 16);
	write(1, &hex[num % 16], 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		print_hex(miniatoi(av[1]));
	write(1, "\n", 1);
	return (0);
}

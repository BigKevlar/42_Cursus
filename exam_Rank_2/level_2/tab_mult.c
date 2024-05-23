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

void	print_num(int num)
{
	char digit;

	if (num >= 10)
		print_num(num / 10);
	digit = (num % 10) + '0';
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

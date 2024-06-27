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

int	main(int ac, char **av)
{
	int	num;
	int	tab;
	int	res;

	if (ac < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	num = 1;
	tab = miniatoi(av[1]);
	while (num <= 9)
	{
		res = num * tab;
		print_num(num);
		write(1, " x ", 3);
		print_num(tab);
		write(1, " = ", 3);
		print_num(res);
		write(1, "\n", 1);
		num++;
	}
	return (0);
}

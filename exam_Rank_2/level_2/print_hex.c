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

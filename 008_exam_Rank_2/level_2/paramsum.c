#include <unistd.h>

void print_num(int num)
{
	char digit;

	if (num >= 10)
		print_num(num / 10);
	digit = (num % 10) + '0';
	write (1, &digit, 1);
}

int main(int ac, char **av)
{
	(void)av;
	print_num(ac - 1);
	write(1, "\n", 1);
	return (0);
}

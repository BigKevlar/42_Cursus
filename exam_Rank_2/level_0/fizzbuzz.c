#include <unistd.h>

int	main(void)
{
	int	num;
	int	aux1;
	int	aux2;

	num = 1;
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
			aux1 = num / 10 + '0';
			aux2 = num % 10 + '0';
			write (1, &aux1, 1);
			write (1, &aux2, 1);
		}
		else
		{
			aux1 = num + '0';
			write(1, &aux1, 1);
		}
		write(1,"\n", 1);
		num++;
	}
	return (0);
}
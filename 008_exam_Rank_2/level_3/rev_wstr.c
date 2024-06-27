#include <unistd.h>

int main(int ac, char **av)
{
	int len = 0;
	int start = 0;
	int end = 0;

	if (ac == 2)
	{
		while (av[1][len] != '\0')
			len++;
		while (len >= 0)
		{
			while (av[1][len] == '\0' || av[1][len] == ' ' || av[1][len] == '\t')
				len--;
			end = len;
			while (av[1][len] && av[1][len] != ' ' && av[1][len] != '\t')
				len--;
			start = len + 1;
			while (start <= end)
			{
				write(1, &av[1][start], 1);
				start++;
			}
			if (len >= 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}

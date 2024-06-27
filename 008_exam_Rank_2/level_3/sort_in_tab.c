#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	c = 0;
	int				tmp;

	while (c < (size - 1))
	{
		if (tab[c] < tab[c + 1])
		{
			tmp = tab[c];
			tab[c] = tab[c + 1];
			tab[c + 1] = tmp;
			c = 0;
		}
		else
			c++;
	}
}

/*
int main(void)
{
	int len = 7; 
	int	numbers[] = {5, 2, 2, 7, 1, 9, 3};

	printf("Array normal: ");
	while (len-- > 0)
		printf("%d ", numbers[len]);
	printf("\n");
	len = 7;
	sort_int_tab(numbers, len);
	printf("Array ordenado: ");
	while (len-- > 0)
		printf("%d ", numbers[len]);
	printf("\n");
	return (0);
}
*/
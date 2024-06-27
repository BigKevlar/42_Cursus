#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	c = 0;
	int	*range = NULL;

	if (start > end)
		range = (int *)malloc(sizeof(int) * (start - end) + 1);
	else if (end > start)
		range = (int *)malloc(sizeof(int) * (end - start) + 1);
	if (!range)
		return (NULL);
	while (start != end)
	{
		range[c] = start;
		c++;
		start++;
	}
	range[c] = start;
	return (range);
}

/*
int		main(void)
{
	int c = 0;
	int *range = NULL;
	int start = -1;
	int end = 2;

	range = ft_range(start, end);
	while (c <= end - start)
	{
		printf("%d\n", range[c]);
		c++;
	}
	return (0);
}
*/

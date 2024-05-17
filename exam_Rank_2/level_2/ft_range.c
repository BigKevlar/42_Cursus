/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

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
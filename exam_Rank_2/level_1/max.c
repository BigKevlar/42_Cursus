/*
Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.
*/

int	max(int *tab, unsigned int len)
{
	int aux = tab[0];

	if (len == 0)
		return (0);
	while (len > 0)
	{
		if (aux < tab[len - 1])
			aux = tab[len - 1];
		len--;
	}
	return (aux);
}
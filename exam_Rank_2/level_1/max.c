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
	int c = 0;
	int aux = tab[c]; //iniciamos la variable aux con el primer nuemro del array, para ir comparando desde el principio.

	if (len == 0) //si la longuitud del array es 0 acabamos sin devolver nada.
		return (0);
	while (c < len)
	{
		if (aux < tab[c])
			aux = tab[c];
		c++;
	}
	return (aux);
}
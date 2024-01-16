/*
Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions: 
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestra funcion ("void", porque no devulve nada) intercambia los valores de "a" con "b" y viceversa.
Inicamos una variable auxiliar "tmp" para guardar uno de los valores para no perderlo.
Introducimos en "tmp" una copia de "a".
Copiamos "b" en "a", y en "b" metemos "tmp", que era la copia de "a".
Finalizamos la funcion.
*/
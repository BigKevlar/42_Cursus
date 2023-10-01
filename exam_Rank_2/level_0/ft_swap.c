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
	int	aux;

	aux = *a; //se utiliza una variable temporal aux para almacenar una de ellas mientras de intercambian los valores.
	*a = *b;
	*b = aux;
}
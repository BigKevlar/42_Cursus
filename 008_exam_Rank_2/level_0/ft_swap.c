void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Nuestra funcion intercambia los valores de dos numeros.
	Inicamos una variable auxiliar "tmp" para guardar uno de los valores y no perderlo.
	Introducimos en "tmp" una copia de "a".
	Copiamos "b" en "a", y en "b" metemos "tmp", que era la copia de "a".
	Finalizamos la funcion.
--------------------------------------------------------------------------------
*/
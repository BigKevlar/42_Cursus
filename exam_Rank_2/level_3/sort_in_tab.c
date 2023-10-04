/*
Nombre de la tarea : sort_int_tab
Ficheros esperados : sort_int_tab.c
Funciones permitidas:
--------------------------------------------------------------------------------

Escriba la siguiente función:

void sort_int_tab(int *tab, unsigned int size);

Debe ordenar (in-place) el array int 'tab', que contiene exactamente 'size'
en orden ascendente.

Los dobles deben preservarse.

La entrada es siempre coherente.
*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	c = 0;
	int	tem;

	while (c < (size - 1))
	{
		if (tab[c] > tab[c + 1])
		{
			tem = tab[c];
			tab[c] = tab[c+ 1];
			tab[c + 1] = tem;
			c = 0;
		}
		else
			c++;
	}
	return ;
}
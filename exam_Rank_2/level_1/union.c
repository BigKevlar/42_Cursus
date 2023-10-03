/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome dos cadenas y muestre, sin dobles, los
caracteres que aparecen en cualquiera de las cadenas.

La pantalla estará en el orden en que aparecen los caracteres en la línea de comandos, y
irá seguido de un \n.

Si el número de argumentos no es 2, el programa muestra \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	str_c = 1;
	int	word_c = 0;
	int	array[255] = {0};

	if (ac == 3)
	{
		while (str_c <= 2) //vamos a repetir este bucle dos veces solo, porque solo tenemos dos argumentos y vamos a iterar el primero y luego el segundo...
		{
			word_c = 0; //... reiniciando siempre la primera letra de cada argumento.
			while (av[str_c][word_c] != '\0')
			{
				if (array[(int)av[str_c][word_c]] == 0) //si la posicion casteada del array es 0 significa que la letra no existe, asi que entra para escribirla y cambia su valor para que no se vuelva a imprimir.
				{
					write(1, &av[str_c][word_c], 1);
					array[(int)av[str_c][word_c]] = 1;
				}
				word_c++; //siguiente letra.
			}
			str_c++; //siguiente argumento.
		}
	}
	write(1, "\n", 1);
	return (0);
}
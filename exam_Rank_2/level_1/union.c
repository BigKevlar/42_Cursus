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
	int	str_cont = 1;
	int	word_cont = 0;
	int	array[255] = {0};

	if (ac == 3)
	{
		while (str_cont < 3)
		{
			word_cont = 0;
			while (av[str_cont][word_cont])
			{
				if (array[(int)av[str_cont][word_cont]] == 0)
				{
					array[(int)av[str_cont][word_cont]] = 1;
					write(1, &av[str_cont][word_cont], 1);
				}
				word_cont++;
			}
			str_cont++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
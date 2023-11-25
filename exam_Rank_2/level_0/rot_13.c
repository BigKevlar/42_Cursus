/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;

	if (ac == 2)
	{
		while (av[1][c] != '\0') //bucle hasta el final del string.
		{
			if ((av[1][c] >= 'a' && av[1][c] <= 'm') || (av[1][c] >= 'A' && av[1][c] <= 'M')) //si la letra está entre las primeras 13 letras del abecedario sumale 13 posiciones.
				av[1][c] += 13;
			else if ((av[1][c] >= 'n' && av[1][c] <= 'z') || (av[1][c] >= 'N' && av[1][c] <= 'Z')) //si la letra está entre las ultimas 13 letras del abecedario restale 13 posiciones, que es como dar la vuelta.
				av[1][c] -= 13;
			write (1, &av[1][c], 1); //tanto si entra en un if como si no pues escribe.
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Incluimos la libreria "unistd.h" para usar la funcion "write".
Nuestro programa imprime un string reemplazando cada letra por la que está 13 posiciones en adelante.
Camos a declarar un contador llamado "c" para iterar entre letras.
Mientras sean solo dos argumentos realiza lo de dentro.

*/
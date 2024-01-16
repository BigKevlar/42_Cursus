/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;

	if (ac == 2)
	{
    	while (av[1][c] != '\0')
		{
			if ((av[1][c] >= 'a' && av[1][c] <= 'y') || (av[1][c] >= 'A' && av[1][c] <= 'Y'))
			{	
				av[1][c]++;
				write(1, &av[1][c], 1);
			}
			else if (av[1][c] == 'z')
				write(1, "a", 1);
			else if (av[1][c] == 'Z')
				write(1, "A", 1);
			else
				write(1, &av[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestro programa imprime un string reemplazando cada letra por la siguiente en su posicion alfabetica.
Incluimos la libreria "unistd.h" para usar la funcion "write".
Camos a declarar un contador llamado "c" para iterar entre letras.
Mientras sean solo dos argumentos realiza lo de dentro.
Vamos a ir recorriendo todo el string e imprimiendo lo que nos encontremos pero con condiciones:
- Si la letra esta entre "a" y "y" o entre "A" y "Y": conviertela en la siguiente letra e imprimela.
- Si es la "z" imprime la "a".
- Si es la "Z" imprime la "A".
- Si no es nada de lo anterior imprimelo sin modificar nada.
- Despues de todo haz subier el contador para iterar sobre la siguiente letra.
Ponemos un salto de linea y finalizamos programa.
*/
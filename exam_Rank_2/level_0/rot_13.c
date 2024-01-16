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
		while (av[1][c] != '\0')
		{
			if ((av[1][c] >= 'a' && av[1][c] <= 'm') || (av[1][c] >= 'A' && av[1][c] <= 'M'))
				av[1][c] += 13;
			else if ((av[1][c] >= 'n' && av[1][c] <= 'z') || (av[1][c] >= 'N' && av[1][c] <= 'Z'))
				av[1][c] -= 13;
			write (1, &av[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
Pseudocódigo:
--------------------------------------------------------------------------------
Nuestro programa imprime un string reemplazando cada letra por la que está 13 posiciones en adelante.
Incluimos la libreria "unistd.h" para usar la funcion "write".
Camos a declarar un contador llamado "c" para iterar entre letras.
Mientras sean solo dos argumentos realiza lo de dentro.
Vamos a ir recorriendo todo el string e imprimiendo lo que nos encontremos pero con dos condiciones:
si la letra encontrada esta entre la 13 primeras ("a" y "m"), da igual si son mayusculas o minusculas, aumenta 13 posiciones,
y si la letra esta entre las 13 ultimas ("n" y "z") resta 13 posiciones.
Luego imprime
Ejemplo:
si la letra es la "i" aumentara 13 posiciones hasta la "u", si es una "t" imprimira una "g" porque resta 13 posiciones,
que es lo mismo que si llegasemos a la "z" y diesemos la vuelta al abecedario.
Luego imprime. Si no es una lletra no entraria en ninguna condicion e imprimiria directamente.
Ponemos un salto de linea y finalizamos programa.
*/
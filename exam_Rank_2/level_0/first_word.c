/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

#include <unistd.h>

int main(int ac, char **av)
{
	int c = 0;

	if (ac == 2)
	{
		while (av[1][c] == ' ' || av[1][c] == '\t')
			c++;
		while (av[1][c] != ' ' && av[1][c] != '\t' && av[1][c] != '\0')
		{
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
Nuestro programa imprime la primera palabra de un string.
Incluimos la libreria "unistd.h" para usar la funcion "write".
El contador "c" lo usaremos para iterar entre las posiciones del argumento.
Si son exactamente dos argumentos entra en la condicion "if", si no pásala.
Saltamos los espacios o tabulaciones que pudieran haber antes de la primera palabra.
Escribe mientras no sea ni espacio, ni tabulacion, ni caracter nulo.
Si no son exactamente dos caracteres, o si finaliza de escribir, escribe un salto de linea y finaliza el programa.
*/
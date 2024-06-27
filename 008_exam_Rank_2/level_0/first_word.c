#include <unistd.h>

int main(int ac, char **av)
{
	int c = 0;

	if (ac == 2)
	{
		while (av[1][c] == ' ' || av[1][c] == '\t')
			c++;
		while (av[1][c] != '\0' && av[1][c] != ' ' && av[1][c] != '\t')
		{
			write (1, &av[1][c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Empezamos el programa con el numero de argumentos y los punteros de los mismos.
	Incluimos la libreria "unistd.h" para usar la funcion "write".
	Nuestro programa imprimirá la primera palabra de un string.
	El contador "c" lo usaremos para iterar entre las posiciones del argumento.
	Si son exactamente dos argumentos entra en la condicion "if", si no pásala.
	Saltamos los espacios o tabulaciones que pudieran haber antes de la primera palabra.
	Escribe mientras no sea ni caracter nulo, ni espacio, ni tabulacion.
	Si no son exactamente dos caracteres, o si finaliza de escribir, escribe un salto de linea.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/
/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program called search_and_replace that takes 3 arguments, the first
arguments is a string in which to replace a letter (2nd argument) by
another one (3rd argument).

If the number of arguments is not 3, just display a newline.

If the second argument is not contained in the first one (the string)
then the program simply rewrites the string followed by a newline.

Examples:
$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;

	if ((ac == 4) && (!av[2][1] && !av[3][1]))
	{
		while (av[1][c] != '\0')
		{
			if (av[1][c] == av[2][0])
				av[1][c] = av[3][0];
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
Nuestro programa cambiara una letra por otra del string que le pasaremos.
Incluimos la libreria "unistd.h" para usar la funcion "write".
Para ello tomará 4 argumentos:
- 0: el nombre del programa.
- 1: la palabra que se reemplazara.
- 2: la letra que sustiruiremos.
- 3: las letra por la que sustituiremos.
Para ello primero condicionaremos que deben de ser exactamente 4 argumentos y que solo podemos
tomar un unico caracter a reemplazar y por el que se reemplazará.
Para ello la condicion será que el string de las plazabras no contienen segundas letras, solo la
primera (letra en posicion 0 del string, no existe letra en la posicion 1).
Ahora crearemos un contador "c" para iterar en las letras del string que cambiaremos sus palabras.
Si la letra del string es la que queremos sustituir hazlo.
Luego escribela, tanto si la ha sustituido como si no, y pasa a la siguiente. Asi hasta recorrelas todas.
Ponemos un salto de linea y finalizamos programa.
*/
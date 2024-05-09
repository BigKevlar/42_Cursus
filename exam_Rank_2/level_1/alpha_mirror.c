/*
Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called alpha_mirror that takes a string and displays this string
after replacing each alphabetical character by the opposite alphabetical
character, followed by a newline.

'a' becomes 'z', 'Z' becomes 'A'
'd' becomes 'w', 'M' becomes 'N'

and so on.

Case is not changed.

If the number of arguments is not 1, display only a newline.

Examples:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int		c = 0;

	if (ac == 2)
	{
		while (av[1][c] != '\0')
		{
			if (av[1][c] >= 'A' && av[1][c] <= 'Z')
				av[1][c] = ('Z' - av[1][c]) + 'A';
			else if (av[1][c] >= 'a' && av[1][c] <= 'z')
				av[1][c] = ('z' - av[1][c]) + 'a';
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
Nuestro programa tomará un string y cambiara sus letras por la opueta en el abecedario.
Incluimos la libreria "unistd.h" para usar la funcion "write".
El contador "c" lo usaremos para iterar entre las posiciones del argumento.
Vamos a probar algo nuevo para simplificar codigo. Vamos a meter todo 2º argumento en un string. 
Si son exactamente dos argumentos entra en la condicion "if", si no pásala.
Mientras dure el argumento que le hemos pasado:
Si esta entre 'A' y 'Z' tenemos que al valor 'Z' en ASCII restarle el de la letra pasada y sumarle el de 'A'.
Para las minusculas igual pero con minusculas.
Por ejemplo, pongamos que es la letra H. Como tomas los valores ASCII quedaria algo asi:
H = (Z - H) + A <------> 72 = (90 - 72) + 65
Se sustituiria por la S, que es la 8A letra del abecedario empezando por abajo, homologo a la H.
Al final escribimos la letra y aumentamos el contador para pasar a la siguiente letra.
Al teminar el bucle, o si no ha entrado en el bucle, imprimimos un salto de linea y fin del programa.
*/
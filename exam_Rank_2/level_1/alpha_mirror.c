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
	int 	c = 0;
	char	*str = av[1]; //provamos a meter el argumento dentro de un string, para simpificar codigo. 

	if (ac == 2)
	{
		while (str[c] != '\0')
		{
			if (str[c] >= 'a' && str[c] <= 'z') //si es minuscula le restamos al caracter ascii z el valor y sumamos a.
				str[c] = ('z' - str[c]) + 'a';
			else if (str[c] >= 'A' && str[c] <= 'Z') //si es minuscula hacemos lo mismo pero con letras mayusculas.
				str[c] = ('Z' - str[c]) + 'A';
			write(1, &str[c], 1);
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
Vamos a probar algo nuevo, para simplificar codigo. Vamos a meter todo el string 
Si son exactamente dos argumentos entra en la condicion "if", si no pásala.

*/
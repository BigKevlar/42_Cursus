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
	int 	c = 0; //provamos a poner el contador solo con una letra para simplificar codigo.
	char	*str = av[1]; //provamos a meter el argumento dentro de un string para simpificar 

	if (ac == 2)
	{
		while (str[c] != '\0')
		{
			if (str[c] >= 'a' && str[c] <= 'z') //si es minuscula le restamos el valor de z y sumamos a.
				str[c] = ('z' - str[c]) + 'a';
			else if (str[c] >= 'A' && str[c] <= 'Z') //si es minuscula le restamos el valor de Z y sumamos A.
				str[c] = ('Z' - str[c]) + 'A';
			write(1, &str[c], 1);
			c++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
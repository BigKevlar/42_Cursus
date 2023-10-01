/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

int	main(int ac, char **av)
{
	int		cont = 0;
	char	word = 0;

	if (ac == 2)
	{
		while (av[1][cont] != '\0')
		{
			word = 1; //inicializamos siempre el bucle con word en 1, para darle el valor numerico correspondiente al numero del abecedario.
			if (av[1][cont] >= 'A' && av[1][cont] <= 'Z')
				word += av[1][cont] - 'A';
			if (av[1][cont] >= 'a' && av[1][cont] <= 'z')
				word += av[1][cont] - 'a';
			while (word != 0) //imprimimos la letra tantas veces como no llegue word a 0, que es su posicion en el calendario.
			{
				write(1, &av[1][cont], 1);
				word--;
			}
			cont++;
		}
	}
    write (1, "\n", 1);
    return (0);
}
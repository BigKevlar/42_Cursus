#include <unistd.h>

int main(int ac, char **av)
{
	int c = 0;

	if (ac == 2)
	{
		while (av[1][c] != '\0')
			c++;
		c--;
		while(av[1][c] == ' ' || av[1][c] == '\t')
			c--;
		while(av[1][c] != ' ' && av[1][c] != '\t')
			c--;
		if (av[1][c] == ' ' || av[1][c] == '\t')
			c++;
		while(av[1][c] != '\0' && av[1][c] != ' ' && av[1][c] != '\t')
		{
			write(1, &av[1][c], 1);
			c++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

//va hasta el final del string.
//retrocede hasta el final de la utima palabras si hay espacios o tabs, y es nulo c.
//ahora retrocede hasta el principio de la palabra si no encuentras espacios ni tabs
// si el sitio donde esta es un espacio o tab avanza una posicion, clocandose en la primera letra de la ultima palabra.
//por ultimo imprime la ultima palabra hasta que sea nulo o encuentre espacio o tab.
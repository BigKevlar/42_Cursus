#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;

	if (ac == 2)
	{
		while (av[1][c] != '\0')
		{
			if (av[1][c] >= 'A' && av[1][c] <= 'Z')
				av[1][c] += 32;
			else if (av[1][c] >= 'a' && av[1][c] <= 'z')
				av[1][c] -= 32;
			write(1, &av[1][c], 1);
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
	Nuestro programa cambiara las minusculas por mayusculas y viceversa (segun tabla ASCII).
	Para ello primero creamos una variable "c" para iterar sobre todoas las letras del string.
	Luego condicionamos que deben ser dos argumentos solo.
	Ahora hacemos un bucle que recorra todo el string y vamos haciendo las condiciones:
	- Si es minuscula aumenta 32 posiciones para convertirla en su homologo en mayuscula.
	- Si es mayuscula restamos 32 posiciones para convertirla en su homologo en minuscula.
	- Al final imprimimos lo que sea que haya en la posicion, cambiada o no.
	Imprimimos un salto de linea.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/
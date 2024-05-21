#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;
	int	repeat = 1;

	if (ac == 2)
	{
		while (av[1][c] != '\0')
		{
			repeat = 1;
			if (av[1][c] >= 'A' && av[1][c] <= 'Z')
				repeat += av[1][c] - 'A';
			else if (av[1][c] >= 'a' && av[1][c] <= 'z')
				repeat += av[1][c] - 'a';
			while (repeat > 0)
			{
				write(1, &av[1][c], 1);
				repeat--;
			}
			c++;
		}
	}
	write (1, "\n", 1);
	return (0);
}

/*
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Empezamos el programa con el numero de argumentos y los punteros de los mismos.
	Incluimos la libreria "unistd.h" para usar la funcion "write".
	Nuestro programa imprimirá por pantalla cada letra del string tantas veces como sea su posicion en el abecedario.
	Vamos a declarar dos variables: un contador llamado "c" para iterar entre letras, y "repeat" simepre en 1 para el valor numerico del abecedario.
	Si el progama recibe exactamente dos argumentos realiza el bucle.
	Mientras el argumento no sea nulo:
	- "repeat" comenzando siempre en 1 para que minimo imprima una vez.
	- Se resta la letra entre "A" o "a" para obtener su posicion en el abecedario, y se le suma el valor a "repeat"
	Por ejemplo:
	Si la letra fuera la "A", "A - A = 0", por lo que "repeat" que es 1 seria "1 = 1 + 0", asi que imprimiria "A" una sola vez.
	Y asi se imprime cada letra tantas veces como su posicion en el abecedario, que se a guardado en "repeat".
	Pasamos a la siguiente letra aumentando "c" para pasar a la siguiente letra si es que existe, y asi con todo el string.
	Imprimimos un salto de linea.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/
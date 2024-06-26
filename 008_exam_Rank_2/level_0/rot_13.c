#include <unistd.h>

int	main(int ac, char **av)
{
	int	c = 0;

	if (ac == 2)
	{
		while (av[1][c] != '\0')
		{
			if ((av[1][c] >= 'A' && av[1][c] <= 'M') || (av[1][c] >= 'a' && av[1][c] <= 'm'))
				av[1][c] += 13;
			else if ((av[1][c] >= 'N' && av[1][c] <= 'Z') || (av[1][c] >= 'n' && av[1][c] <= 'z'))
				av[1][c] -= 13;
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
	Nuestro programa imprime un string reemplazando cada letra por la que está 13 posiciones en adelante.
	Vamos a declarar un contador llamado "c" para iterar entre letras.
	Mientras sean solo dos argumentos realiza lo de dentro.
	Vamos a ir recorriendo todo el string e imprimiendo lo que nos encontremos pero con dos condiciones:
	- Si la letra encontrada esta entre la 13 primeras ("a" y "m" ò "A" y "M") aumenta 13 posiciones.
	- Si la letra esta entre las 13 ultimas ("n" y "z" ò "N" y "Z") resta 13 posiciones.
	Tanto si cambia o no de posiciones imprime el contenido de la posicion del string.
	Ejemplo:
	Si la letra es la "i" aumentara 13 posiciones hasta la "u", si es una "t" imprimira una "g" porque resta 13 posiciones,
	que es lo mismo que si llegasemos a la "z" y diesemos la vuelta al abecedario. Luego imprime.
	Si no es una letra no entraria en ninguna condicion e imprimiria directamente.
	Imprimimos un salto de linea.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/
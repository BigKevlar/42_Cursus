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
--------------------------------------------------------------------------------
Pseudocódigo:
--------------------------------------------------------------------------------
	Empezamos el programa con el numero de argumentos y los punteros de los mismos.
	Incluimos la libreria "unistd.h" para usar la funcion "write".
	Nuestro programa cambiara una letra por otra del string que le pasaremos.
	Para ello tomará 4 argumentos:
	- 0: el nombre del programa.
	- 1: la palabra que se reemplazara.
	- 2: la letra que sustiruiremos.
	- 3: las letra por la que sustituiremos.
	Para ello primero condicionaremos que deben de ser exactamente 4 argumentos y que solo podemos
	tomar un unico caracter a reemplazar y por el que se reemplazará.
	La condicion será que el string de las plazabras no contienen segundas letras, solo la
	primera (letra en posicion 0 del string, no existe letra en la posicion 1).
	Ahora crearemos un contador "c" para iterar en las letras del string que cambiaremos sus palabras.
	Si la letra del string es la que queremos sustituir hazlo.
	Luego escribela, tanto si la ha sustituido como si no, y pasa a la siguiente. Asi hasta recorrelas todas.
	Imprimimos un salto de linea.
	Finalizamos el programa.
--------------------------------------------------------------------------------
*/